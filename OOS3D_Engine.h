///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/toolbar.h>
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/treelist.h>
#include <wx/splitter.h>
#include <wx/notebook.h>
#include <wx/aui/auibook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
#include <wx/filepicker.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class OOS3D_Engine
///////////////////////////////////////////////////////////////////////////////
class OOS3D_Engine : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_file_menu;
		wxMenu* m_edit_menu;
		wxMenu* m_project_menu;
		wxMenu* m_build_menu;
		wxMenu* m_help_menu;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* m_newProject_tool;
		wxToolBarToolBase* m_openProject_tool;
		wxToolBarToolBase* m_saveProject_tool;
		wxToolBarToolBase* m_play_tool;
		wxToolBarToolBase* m_stop_tool;
		wxToolBarToolBase* m_view_tool;
		wxToolBarToolBase* m_select_tool;
		wxToolBarToolBase* m_boxSelect_tool;
		wxToolBarToolBase* m_move_tool;
		wxToolBarToolBase* m_rotate_tool;
		wxToolBarToolBase* m_scale_tool;
		wxToolBarToolBase* m_terrain_tool;
		wxToolBarToolBase* m_addActor_tool;
		wxToolBarToolBase* m_addLight_tool;
		wxToolBarToolBase* m_addCamera_tool;
		wxToolBarToolBase* m_effect_tool;
		wxToolBarToolBase* m_event_tool;
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel19;
		wxNotebook* m_notebook3;
		wxPanel* m_projectBrowser_panel;
		wxSplitterWindow* m_splitter3;
		wxPanel* m_panel14;
		wxTreeCtrl* m_project_treeCtrl;
		wxPanel* m_panel15;
		wxTreeListCtrl* m_projectProperties_treeListCtrl;
		wxPanel* m_assetBrowser_panel;
		wxTreeCtrl* m_assets_treeCtrl;
		wxPanel* m_stageNotebookContainer_panel;
		wxAuiNotebook* m_stage_auinotebook;
		wxStatusBar* m_statusBar1;

		// Virtual event handlers, override them in your derived class
		virtual void OnNewProjectMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadProjectMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveProjectMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExitMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUndoMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRedoMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDuplicateMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectAllMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewStageMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewScriptMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportMeshMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportAudioMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportTextureMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportVideoMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportScriptMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportDataMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProjectSettingsMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRunGameMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRunStageMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbortMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDistributeMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAboutMenuSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBoxSelectToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRotateToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnScaleToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetTerrainToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddActorToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddLightToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddCameraToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddEffectToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddEventToolSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProjectTreeContextMenu( wxTreeEvent& event ) { event.Skip(); }


	public:

		OOS3D_Engine( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("OutOfSpace Engine"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1333,775 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~OOS3D_Engine();

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 177 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( OOS3D_Engine::m_splitter2OnIdle ), NULL, this );
		}

		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 253 );
			m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( OOS3D_Engine::m_splitter3OnIdle ), NULL, this );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class newProjectDialog
///////////////////////////////////////////////////////////////////////////////
class newProjectDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* m_projectName_textCtrl;
		wxButton* m_cancel_button;
		wxButton* m_ok_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		newProjectDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create New Project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 396,167 ), long style = wxDEFAULT_DIALOG_STYLE );

		~newProjectDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class newStageDialog
///////////////////////////////////////////////////////////////////////////////
class newStageDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* m_stageName_textCtrl;
		wxStaticText* m_staticText41;
		wxComboBox* m_stageType_comboBox;
		wxButton* m_cancel_button;
		wxButton* m_ok_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		newStageDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create New Stage"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 396,167 ), long style = wxDEFAULT_DIALOG_STYLE );

		~newStageDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class newScriptDialog
///////////////////////////////////////////////////////////////////////////////
class newScriptDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* m_scriptName_textCtrl;
		wxButton* m_cancel_button;
		wxButton* m_ok_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		newScriptDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create New Script"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 396,167 ), long style = wxDEFAULT_DIALOG_STYLE );

		~newScriptDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class importModelDialog
///////////////////////////////////////////////////////////////////////////////
class importModelDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText5;
		wxFilePickerCtrl* m_filePicker1;
		wxCheckBox* m_importModels_checkBox;
		wxCheckBox* m_importTextures_checkBox;
		wxCheckBox* m_importArmature_checkBox;
		wxCheckBox* m_importAnimation_checkBox;
		wxCheckBox* m_importScene_checkBox;
		wxButton* m_cancel_button;
		wxButton* m_import_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		importModelDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Import 3D Mesh"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 436,274 ), long style = wxDEFAULT_DIALOG_STYLE );

		~importModelDialog();

};

