/* Include headers */
#include "frame.hpp"

/* Frame constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Frame align */
	Center(); // or Centre()
}