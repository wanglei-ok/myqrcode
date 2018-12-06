// QRCode.cpp : implementation file
//

#include "stdafx.h"
#include "QRCode.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQRCode

CQRCode::CQRCode()
{
	m_bTextMode = TRUE;
	m_qrcode = NULL;
}

CQRCode::~CQRCode()
{
	delete m_qrcode;
}


BEGIN_MESSAGE_MAP(CQRCode, CStatic)
	//{{AFX_MSG_MAP(CQRCode)
	ON_WM_PAINT()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQRCode message handlers

void CQRCode::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rc;
	GetClientRect(&rc);

	//Ìî³ä±³¾°É«
	dc.FillSolidRect( &rc, RGB(255,255,255));

	if ( m_bTextMode )
	{
		CFont *oldfont = dc.SelectObject( GetParent()->GetFont() );
		DWORD flag = DT_EDITCONTROL|DT_WORDBREAK;
		if (GetStyle() & SS_LEFT )
		{
			flag |= DT_LEFT;
		}

		if (GetStyle() & SS_ENDELLIPSIS )
		{
			flag |= DT_END_ELLIPSIS;
		}

		if (GetStyle() & SS_CENTER )
		{
			flag |= DT_CENTER;
		}

		if (GetStyle() & SS_RIGHT )
		{
			flag |= DT_RIGHT;
		}
		if (GetStyle() & SS_PATHELLIPSIS ) 
		{
			flag |= DT_PATH_ELLIPSIS;
		}
		if (GetStyle() & SS_WORDELLIPSIS )
		{
			flag |= DT_WORD_ELLIPSIS;
		}
		if (GetStyle() & SS_CENTERIMAGE )
		{
			//´¹Ö±¾ÓÖÐ
			CRect rcText = rc;
			dc.DrawText( m_text, &rcText, flag|DT_CALCRECT );
			rcText.OffsetRect( 0, (rc.Height() - rcText.Height())/2 );
			dc.DrawText( m_text, &rcText, flag );
		}else
		{
			dc.DrawText( m_text, &rc, flag );
		}
		
		dc.SelectObject( oldfont );
		//dc.DrawText( m_text, &rc, DT_CENTER|DT_END_ELLIPSIS|DT_WORDBREAK );
	}else if ( m_qrcode )
	{		
		BITMAP bm;
		m_qrcode->GetBitmap(&bm);

		CDC memdc;
		memdc.CreateCompatibleDC( &dc );
		CBitmap * oldbmp = memdc.SelectObject(m_qrcode);
		dc.BitBlt( (rc.Width() - bm.bmWidth)/2, (rc.Height() - bm.bmHeight)/2, bm.bmWidth, bm.bmHeight, &memdc, 0, 0, SRCCOPY ); 
		memdc.SelectObject(oldbmp);
	}
	
	// Do not call CStatic::OnPaint() for painting messages
}

LRESULT CQRCode::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if ( message == WM_SETTEXT )
	{
		m_text = (LPCTSTR)lParam;
		//Ë¢ÐÂ
		refresh();
		return TRUE;
	}else if ( message == WM_GETTEXT  )
	{
		if ( lParam == NULL || wParam == 0 ) return 0;

		if ( lstrcpyn( (char*)lParam, m_text, (int)wParam ) )
		{
			return lstrlen((const char*)lParam);
		}else
		{
			return 0;
		}
	}else if ( message == WM_GETTEXTLENGTH )
	{
		return m_text.GetLength();
	}
			
	return CStatic::WindowProc(message, wParam, lParam);
}

void CQRCode::refresh()
{
	CRect rc;
	GetClientRect(&rc);

	if ( m_qrcode )
	{
		delete m_qrcode;
		m_qrcode = NULL;
	}
	if ( !m_bTextMode )
	{
		QRcode *pQRC = QRcode_encodeString(m_text, 0, QR_ECLEVEL_H, QR_MODE_8, 1);
		if ( pQRC )
		{
			unsigned char *pSourceData;
			//¿í¶È
			int w;
			if ( rc.Width() < rc.Height() )
			{
				w = rc.Width();
			}else
			{
				w = rc.Height();
			}
			int scale = w / pQRC->width;
			int widthAdjusted = scale * pQRC->width;
			CClientDC dc(this);
			CDC memdc;
			memdc.CreateCompatibleDC( &dc );
			m_qrcode = new CBitmap;
			m_qrcode->CreateCompatibleBitmap( &dc, widthAdjusted, widthAdjusted );
			CBitmap * oldBmp = memdc.SelectObject( m_qrcode );

			//Ìî³ä°×É«±³¾°
			memdc.FillSolidRect( 0, 0, widthAdjusted, widthAdjusted, RGB(255,255,255));
			pSourceData = pQRC->data;
			for ( int y = 0; y < pQRC->width; y++ )
			{
				for ( int x = 0; x < pQRC->width; x++ )
				{
					if ( *pSourceData & 1 )
					{
						for ( int l = 0; l < scale; l++ )
						{
							for ( int n = 0; n < scale; n++ )
							{
								memdc.SetPixel(x*scale+n, y*scale+l, RGB(0,0,0));
							}
						}
					}
					pSourceData++;
				}
			}
			
			memdc.SelectObject( oldBmp );
			QRcode_free(pQRC);
		}
	}

	Invalidate();
}


void CQRCode::SetText(const CString &str, BOOL bTextMode)
{
	m_bTextMode = bTextMode;
	SetWindowText( str );
}

void CQRCode::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	refresh();	
}
