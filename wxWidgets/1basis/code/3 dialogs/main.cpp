/* Include headers */
#include "main.hpp"
#include "frame.hpp"

/* Implement app */
IMPLEMENT_APP(App)

/* Accessor */
bool App::OnInit()
{

    /* Frame class pointer, wxT("Frame") - frame title */
    Frame *frame = new Frame(wxT("Frame"));
    
    /* Show frame */
    frame->Show(true);

    /* Custom dialog screen */
    CustomDialogScreen *custom = new CustomDialogScreen(wxT("CustomDialogScreen"));
    custom->Show(true);

    return true;
    
}