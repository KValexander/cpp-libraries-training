/* Include libraries */
#include <wx/wx.h>
#include <wx/listbox.h>
#include <wx/notebook.h>
#include <wx/grid.h>

/* Cosntants */
#define WIDTH 450
#define HEIGHT 450

/* Enum */
enum {
	ID_RENAME = 1,
	ID_LISTBOX,
};

/* Notebook class extends wxGrid */
class Notebook : public wxGrid
{

/* Public */
public:

	/* Cosntructor */
	Notebook(wxNotebook *parent);

};

/* Listbox class extends wxPanel */
class Listbox : public wxPanel
{

/* Public */
public:

	/* Constructor */
	Listbox(wxPanel *parent);

	/* Events */
	void OnNew(wxCommandEvent &event);
	void OnRename(wxCommandEvent &event);
	void OnDelete(wxCommandEvent &event);
	void OnClear(wxCommandEvent &event);

	/* Listbox */
	wxListBox *lb;

	/* Buttons */
	wxButton *btn_new;
	wxButton *btn_rename;
	wxButton *btn_clear;
	wxButton *btn_delete;

};

/* Frame class extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);


	/* Scroll window screen */
	void ScrollWindowScreen();


	/* Notebook screen */
	void NotebookScreen();

	/* Quit */
	void OnQuit(wxCommandEvent &event);


	/* Listbox screen */
	void ListBoxScreen();

	/* Listbox */
	Listbox *lb;

	/* Listbox */
	wxListBox *listbox;

	/* Double click */
	void OnDblClick(wxCommandEvent &event);

};