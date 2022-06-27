/* Include libraries */
#include <stdlib.h>
#include <time.h>

/* Include headers */
#include "frame.hpp"

/* Frame constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Connect context */
	Connect(wxEVT_PAINT, wxPaintEventHandler(Frame::OnPaint));

	/* Rand init */
	srand(time(NULL));

	/* Frame align */
	Center(); // or Centre()
}

/* Contexts */
void Frame::OnPaint(wxPaintEvent &event)
{

	/* Paint DC */
	wxPaintDC dc(this);


	/* Draw line */
	wxCoord x1 = 40, y1 = 77;
	dc.DrawLine(x1, y1, 200, 77);

	/* Draw text */
	dc.DrawText(wxT("Русский"), 40, 60);
	dc.DrawText(wxT("English"), 70, 80);

	/* Draw points */
	for(int i = 0; i < 1000; i++)
		dc.DrawPoint(rand() % WIDTH + 1, rand() % HEIGHT + 1);


	/* Colours */
	wxColour col1, col2;
	col1.Set(wxT("#0c0c0c"));
	col2.Set(wxT("#000000"));

	/* Brush */
	wxBrush brush(wxColour(255, 255, 255), wxTRANSPARENT);
	dc.SetBrush(brush);

	/* Pen */
	dc.SetPen(wxPen(col1, 1, wxSOLID));
	dc.DrawRectangle(10, 15, 90, 60);

	dc.SetPen(wxPen(col1, 1, wxDOT));
	dc.DrawRectangle(130, 15, 90, 60);

	dc.SetPen(wxPen(col1, 1, wxLONG_DASH));
	dc.DrawRectangle(250, 15, 90, 60);

	dc.SetPen(wxPen(col1, 1, wxSHORT_DASH));
	dc.DrawRectangle(10, 105, 90, 60);

	dc.SetPen(wxPen(col1, 1, wxDOT_DASH));
	dc.DrawRectangle(130, 105, 90, 60);

	dc.SetPen(wxPen(col1, 1, wxTRANSPARENT));
	dc.DrawRectangle(250, 105, 90, 60);

	/* Regions */
	wxColour black, gray, white, red, blue;
	wxColour orange, green, brown;

	black.Set(wxT("#000000"));
	gray.Set(wxT("#d4d4d4"));
	white.Set(wxT("#ffffff"));
	red.Set(wxT("#ff0000"));
	orange.Set(wxT("#fa8e00"));
	green.Set(wxT("#619e1b"));
	brown.Set(wxT("#715b33"));
	blue.Set(wxT("#0d0060"));

	dc.SetPen(wxPen(gray));

	dc.DrawRectangle(20, 20, 50, 50);
	dc.DrawRectangle(30, 40, 50, 50);

	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(100, 20, 50, 50);
	dc.DrawRectangle(110, 40, 50, 50); 
	wxRegion region1(100, 20, 50, 50);
	wxRegion region2(110, 40, 50, 50);
	region1.Intersect(region2);
	wxRect rect1 = region1.GetBox();
	dc.SetClippingRegion(region1);
	dc.SetBrush(wxBrush(red));
	dc.DrawRectangle(rect1);
	dc.DestroyClippingRegion();

	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(180, 20, 50, 50);
	dc.DrawRectangle(190, 40, 50, 50);
	wxRegion region3(180, 20, 50, 50);
	wxRegion region4(190, 40, 50, 50);
	region3.Union(region4);
	dc.SetClippingRegion(region3);
	wxRect rect2 = region3.GetBox();
	dc.SetBrush(wxBrush(orange));
	dc.DrawRectangle(rect2);
	dc.DestroyClippingRegion();

	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(20, 120, 50, 50);
	dc.DrawRectangle(30, 140, 50, 50);
	wxRegion region5(20, 120, 50, 50);
	wxRegion region6(30, 140, 50, 50);
	region5.Xor(region6);
	wxRect rect3 = region5.GetBox();
	dc.SetClippingRegion(region5);
	dc.SetBrush(wxBrush(green));
	dc.DrawRectangle(rect3);
	dc.DestroyClippingRegion();

	dc.SetBrush(wxBrush(white));
	dc.DrawRectangle(100, 120, 50, 50);
	dc.DrawRectangle(110, 140, 50, 50);
	wxRegion region7(100, 120, 50, 50);
	wxRegion region8(110, 140, 50, 50);
	region7.Subtract(region8);
	wxRect rect4 = region7.GetBox();
	dc.SetClippingRegion(region7);
	dc.SetBrush(wxBrush(brown));
	dc.DrawRectangle(rect4);
	dc.DestroyClippingRegion();

	dc.SetBrush(white);
	dc.DrawRectangle(180, 120, 50, 50);
	dc.DrawRectangle(190, 140, 50, 50);
	wxRegion region9(180, 120, 50, 50);
	wxRegion region10(190, 140, 50, 50);
	region10.Subtract(region9);
	wxRect rect5 = region10.GetBox();
	dc.SetClippingRegion(region10);
	dc.SetBrush(wxBrush(blue));
	dc.DrawRectangle(rect5);
	dc.DestroyClippingRegion();

	/* Gradient */
	col1.Set(wxT("#e12223"));
	col2.Set(wxT("#000000"));

	dc.GradientFillLinear(wxRect(120, 120, 180, 40), col1, col2, wxNORTH);
	dc.GradientFillLinear(wxRect(120, 180, 180, 40), col1, col2, wxSOUTH);
	dc.GradientFillLinear(wxRect(120, 240, 180, 40), col1, col2, wxEAST);
	dc.GradientFillLinear(wxRect(120, 300, 180, 40), col1, col2, wxWEST); 

	/* Shapes */
	wxPoint lines[] = { wxPoint(20, 260), wxPoint(100, 260), wxPoint(20, 210), wxPoint(100, 210) };
	wxPoint polygon[] = { wxPoint(130, 140), wxPoint(180, 170), wxPoint(180, 140), wxPoint(220, 110), wxPoint(140, 100) };
	wxPoint splines[] = { wxPoint(240, 170), wxPoint(280, 170), wxPoint(285, 110), wxPoint(325, 110) };

	dc.SetPen(wxPen(black));
	dc.SetBrush(wxBrush(white));

	dc.DrawEllipse(20, 20, 90, 60);
	dc.DrawRoundedRectangle(130, 20, 90, 60, 10);
	dc.DrawArc(240, 40, 340, 40, 290, 20);

	dc.DrawPolygon(4, polygon);
	dc.DrawRectangle(20, 120, 80, 50);
	dc.DrawSpline(4, splines);

	dc.DrawLines(4, lines);
	dc.DrawCircle(170, 230, 35);
	dc.DrawRectangle(250, 200, 60, 60);

}