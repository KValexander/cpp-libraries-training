/* Include libraries */
#include <wx/treectrl.h>
#include <wx/splitter.h>
#include <wx/dir.h>

/* Include headers */
#include "frame.hpp"

/* Frame constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* DOESN'T WORK */

	/* Splitters */
	wxSplitterWindow *spl1 = new wxSplitterWindow(this, -1);
	wxSplitterWindow *spl2 = new wxSplitterWindow(spl1, -1);

	/* Ctrls */
	gdc = new wxGenericDirCtrl(spl1, -1, wxT("/home/"), wxPoint(-1, -1), wxSize(-1, -1), wxDIRCTRL_DIR_ONLY);
	lc1 = new wxListCtrl(spl2, -1, wxPoint(-1, -1), wxSize(-1, -1), wxLC_LIST);
	lc2 = new wxListCtrl(spl2, -1, wxPoint(-1, -1), wxSize(-1, -1), wxLC_LIST);

	/* Target */
	Target *target = new Target(lc2);
	lc2->SetDropTarget(target);

	/* Tree ctrl */
	wxTreeCtrl *tree = gdc->GetTreeCtrl();
	spl2->SplitHorizontally(lc1, lc2);
	spl1->SplitVertically(gdc, lc1);

	/* Connects */
	Connect(lc1->GetId(), wxEVT_COMMAND_LIST_BEGIN_DRAG, wxListEventHandler(Frame::OnDragInit));
	Connect(tree->GetId(), wxEVT_COMMAND_TREE_SEL_CHANGED, wxCommandEventHandler(Frame::OnSelect));

	/* Frame align */
	Center(); // or Centre()
}

/* Target constructor */
Target::Target(wxListCtrl *owner)
{
	this->owner = owner;
}

/* Drop text */
bool Target::OnDropText(wxCoord x, wxCoord y, const wxString &data)
{
	owner->InsertItem(0, data);
	return true;
}

/* Select */
void Frame::OnSelect(wxCommandEvent &event)
{

	/* Path */
	wxString filename;
	wxString path = gdc->GetPath();
	wxDir dir(path);

	/* Cont */
	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);
	int i = 0; // why?

	/* Clear lists */
	lc1->ClearAll();
	lc2->ClearAll();

	/* Insert items */
	while(cont) {
		lc1->InsertItem(i ,filename);
		cont = dir.GetNext(&filename);
		i++; // why?
	}

}

/* Drag init */
void Frame::OnDragInit(wxListEvent &event)
{

	/* Get item text */
	wxString text = lc1->GetItemText(event.GetIndex());

	/* Drag drop */
	wxTextDataObject tdo(text);
	wxDropSource tds(tdo, lc1);
	tds.DoDragDrop(wxDrag_CopyOnly);

}