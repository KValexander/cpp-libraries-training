/* Include headers */
#include "main.hpp"
#include "frame.hpp"

/* Implement app */
wxIMPLEMENT_APP(MyApp);

/* Accessor */
bool MyApp::OnInit()
{

    /* Frame class pointer, wxT("Frame") - frame title */
    Frame *frame = new Frame(wxT("Frame"));
    
    /* Show frame */
    frame->Show(true);

    return true;
    
}