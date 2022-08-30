///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "OOS3D_Engine.h"

///////////////////////////////////////////////////////////////////////////

OOS3D_Engine::OOS3D_Engine( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_file_menu = new wxMenu();
	wxMenuItem* m_newProject_menuItem;
	m_newProject_menuItem = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("New Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_newProject_menuItem );

	wxMenuItem* m_loadProject_menuItem;
	m_loadProject_menuItem = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("Load Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_loadProject_menuItem );

	wxMenuItem* m_saveProject_menuItem;
	m_saveProject_menuItem = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("Save Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_saveProject_menuItem );

	m_file_menu->AppendSeparator();

	wxMenuItem* m_exit_menuItem;
	m_exit_menuItem = new wxMenuItem( m_file_menu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file_menu->Append( m_exit_menuItem );

	m_menubar1->Append( m_file_menu, wxT("File") );

	m_edit_menu = new wxMenu();
	wxMenuItem* m_undo_menuItem;
	m_undo_menuItem = new wxMenuItem( m_edit_menu, wxID_ANY, wxString( wxT("Undo") ) , wxEmptyString, wxITEM_NORMAL );
	m_edit_menu->Append( m_undo_menuItem );

	wxMenuItem* m_redo_menuItem;
	m_redo_menuItem = new wxMenuItem( m_edit_menu, wxID_ANY, wxString( wxT("Redo") ) , wxEmptyString, wxITEM_NORMAL );
	m_edit_menu->Append( m_redo_menuItem );

	m_edit_menu->AppendSeparator();

	wxMenuItem* m_duplicate_menuItem;
	m_duplicate_menuItem = new wxMenuItem( m_edit_menu, wxID_ANY, wxString( wxT("Duplicate") ) , wxEmptyString, wxITEM_NORMAL );
	m_edit_menu->Append( m_duplicate_menuItem );

	wxMenuItem* m_delete_menuItem;
	m_delete_menuItem = new wxMenuItem( m_edit_menu, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	m_edit_menu->Append( m_delete_menuItem );

	m_edit_menu->AppendSeparator();

	wxMenuItem* m_selectAll_menuItem;
	m_selectAll_menuItem = new wxMenuItem( m_edit_menu, wxID_ANY, wxString( wxT("Select All") ) , wxEmptyString, wxITEM_NORMAL );
	m_edit_menu->Append( m_selectAll_menuItem );

	m_menubar1->Append( m_edit_menu, wxT("Edit") );

	m_project_menu = new wxMenu();
	wxMenuItem* m_newStage_menuItem;
	m_newStage_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("New Stage") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_newStage_menuItem );

	wxMenuItem* m_newScript_menuItem;
	m_newScript_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("New Script") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_newScript_menuItem );

	m_project_menu->AppendSeparator();

	wxMenuItem* m_import3DAssets_menuItem;
	m_import3DAssets_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Import Mesh") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_import3DAssets_menuItem );

	wxMenuItem* m_importAudio_menuItem;
	m_importAudio_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Import Audio") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_importAudio_menuItem );

	wxMenuItem* m_importTextures_menuItem;
	m_importTextures_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Import Textures") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_importTextures_menuItem );

	wxMenuItem* m_importVideo_menuItem;
	m_importVideo_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Import Video") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_importVideo_menuItem );

	wxMenuItem* m_importScripts_menuItem;
	m_importScripts_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Import Scripts") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_importScripts_menuItem );

	wxMenuItem* m_importData_menuItem;
	m_importData_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Import Data") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_importData_menuItem );

	m_project_menu->AppendSeparator();

	wxMenuItem* m_projectSettings_menuItem;
	m_projectSettings_menuItem = new wxMenuItem( m_project_menu, wxID_ANY, wxString( wxT("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	m_project_menu->Append( m_projectSettings_menuItem );

	m_menubar1->Append( m_project_menu, wxT("Project") );

	m_build_menu = new wxMenu();
	wxMenuItem* m_run_menuItem;
	m_run_menuItem = new wxMenuItem( m_build_menu, wxID_ANY, wxString( wxT("Run Game") ) , wxEmptyString, wxITEM_NORMAL );
	m_build_menu->Append( m_run_menuItem );

	wxMenuItem* m_runStage_menuItem;
	m_runStage_menuItem = new wxMenuItem( m_build_menu, wxID_ANY, wxString( wxT("Run Stage") ) , wxEmptyString, wxITEM_NORMAL );
	m_build_menu->Append( m_runStage_menuItem );

	m_build_menu->AppendSeparator();

	wxMenuItem* m_abortRun_menuItem;
	m_abortRun_menuItem = new wxMenuItem( m_build_menu, wxID_ANY, wxString( wxT("Stop Execution") ) , wxEmptyString, wxITEM_NORMAL );
	m_build_menu->Append( m_abortRun_menuItem );

	m_build_menu->AppendSeparator();

	wxMenuItem* m_dist_menuItem;
	m_dist_menuItem = new wxMenuItem( m_build_menu, wxID_ANY, wxString( wxT("Distribute Game") ) , wxEmptyString, wxITEM_NORMAL );
	m_build_menu->Append( m_dist_menuItem );

	m_menubar1->Append( m_build_menu, wxT("Build") );

	m_help_menu = new wxMenu();
	wxMenuItem* m_about_menuItem;
	m_about_menuItem = new wxMenuItem( m_help_menu, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_help_menu->Append( m_about_menuItem );

	m_menubar1->Append( m_help_menu, wxT("Help") );

	this->SetMenuBar( m_menubar1 );

	m_toolBar1 = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
	m_newProject_tool = m_toolBar1->AddTool( wxID_ANY, wxT("New Project"), wxArtProvider::GetBitmap( wxART_NEW, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("New Project"), wxEmptyString, NULL );

	m_openProject_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Open Project"), wxArtProvider::GetBitmap( wxART_FILE_OPEN, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Open Existing Project"), wxEmptyString, NULL );

	m_saveProject_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Save Project"), wxArtProvider::GetBitmap( wxART_FILE_SAVE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxT("Save Current Project"), wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	m_play_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Play"), wxBitmap( wxT("gfx/play.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Test Run"), wxEmptyString, NULL );

	m_stop_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Stop"), wxBitmap( wxT("gfx/stop.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Abort Test Run"), wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	m_view_tool = m_toolBar1->AddTool( wxID_ANY, wxT("View"), wxBitmap( wxT("gfx/view.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_select_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Select"), wxBitmap( wxT("gfx/cursor.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxT("Single Select"), wxEmptyString, NULL );

	m_boxSelect_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Box Select"), wxBitmap( wxT("gfx/box_select.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxT("Box Select"), wxEmptyString, NULL );

	m_move_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Move"), wxBitmap( wxT("gfx/move.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxT("Move"), wxEmptyString, NULL );

	m_rotate_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Rotate"), wxBitmap( wxT("gfx/rotate.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxT("Rotate"), wxEmptyString, NULL );

	m_scale_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Scale"), wxBitmap( wxT("gfx/scale.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxT("Scale"), wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	m_terrain_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Set Terrain"), wxBitmap( wxT("gfx/terrain.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_addActor_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Add Actor"), wxBitmap( wxT("gfx/add_actor.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add Actor"), wxEmptyString, NULL );

	m_addLight_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Add Light"), wxBitmap( wxT("gfx/add_light.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add Light"), wxEmptyString, NULL );

	m_addCamera_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Add Camera"), wxBitmap( wxT("gfx/add_camera.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add Camera"), wxEmptyString, NULL );

	m_effect_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Effect"), wxBitmap( wxT("gfx/effect.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add Effect"), wxEmptyString, NULL );

	m_event_tool = m_toolBar1->AddTool( wxID_ANY, wxT("Event"), wxBitmap( wxT("gfx/event.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add Event"), wxEmptyString, NULL );

	m_toolBar1->Realize();

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( OOS3D_Engine::m_splitter2OnIdle ), NULL, this );

	m_panel19 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );

	m_notebook3 = new wxNotebook( m_panel19, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_projectBrowser_panel = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	m_splitter3 = new wxSplitterWindow( m_projectBrowser_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( OOS3D_Engine::m_splitter3OnIdle ), NULL, this );

	m_panel14 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_project_treeCtrl = new wxTreeCtrl( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer14->Add( m_project_treeCtrl, 1, wxALL|wxEXPAND, 5 );


	m_panel14->SetSizer( bSizer14 );
	m_panel14->Layout();
	bSizer14->Fit( m_panel14 );
	m_panel15 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_projectProperties_treeListCtrl = new wxTreeListCtrl( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTL_DEFAULT_STYLE );

	bSizer15->Add( m_projectProperties_treeListCtrl, 1, wxEXPAND | wxALL, 5 );


	m_panel15->SetSizer( bSizer15 );
	m_panel15->Layout();
	bSizer15->Fit( m_panel15 );
	m_splitter3->SplitHorizontally( m_panel14, m_panel15, 253 );
	bSizer18->Add( m_splitter3, 1, wxEXPAND, 5 );


	m_projectBrowser_panel->SetSizer( bSizer18 );
	m_projectBrowser_panel->Layout();
	bSizer18->Fit( m_projectBrowser_panel );
	m_notebook3->AddPage( m_projectBrowser_panel, wxT("Project"), true );
	m_assetBrowser_panel = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	m_assets_treeCtrl = new wxTreeCtrl( m_assetBrowser_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer19->Add( m_assets_treeCtrl, 1, wxALL|wxEXPAND, 5 );


	m_assetBrowser_panel->SetSizer( bSizer19 );
	m_assetBrowser_panel->Layout();
	bSizer19->Fit( m_assetBrowser_panel );
	m_notebook3->AddPage( m_assetBrowser_panel, wxT("Assets"), false );

	bSizer121->Add( m_notebook3, 1, wxEXPAND | wxALL, 5 );


	m_panel19->SetSizer( bSizer121 );
	m_panel19->Layout();
	bSizer121->Fit( m_panel19 );
	m_stageNotebookContainer_panel = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_stage_auinotebook = new wxAuiNotebook( m_stageNotebookContainer_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE );

	bSizer13->Add( m_stage_auinotebook, 1, wxEXPAND | wxALL, 5 );


	m_stageNotebookContainer_panel->SetSizer( bSizer13 );
	m_stageNotebookContainer_panel->Layout();
	bSizer13->Fit( m_stageNotebookContainer_panel );
	m_splitter2->SplitVertically( m_panel19, m_stageNotebookContainer_panel, 177 );
	bSizer111->Add( m_splitter2, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer111, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_file_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnNewProjectMenuSelect ), this, m_newProject_menuItem->GetId());
	m_file_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnLoadProjectMenuSelect ), this, m_loadProject_menuItem->GetId());
	m_file_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnSaveProjectMenuSelect ), this, m_saveProject_menuItem->GetId());
	m_file_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnExitMenuSelect ), this, m_exit_menuItem->GetId());
	m_edit_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnUndoMenuSelect ), this, m_undo_menuItem->GetId());
	m_edit_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnRedoMenuSelect ), this, m_redo_menuItem->GetId());
	m_edit_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnDuplicateMenuSelect ), this, m_duplicate_menuItem->GetId());
	m_edit_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnDeleteMenuSelect ), this, m_delete_menuItem->GetId());
	m_edit_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnSelectAllMenuSelect ), this, m_selectAll_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnNewStageMenuSelect ), this, m_newStage_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnNewScriptMenuSelect ), this, m_newScript_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnImportMeshMenuSelect ), this, m_import3DAssets_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnImportAudioMenuSelect ), this, m_importAudio_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnImportTextureMenuSelect ), this, m_importTextures_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnImportVideoMenuSelect ), this, m_importVideo_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnImportScriptMenuSelect ), this, m_importScripts_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnImportDataMenuSelect ), this, m_importData_menuItem->GetId());
	m_project_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnProjectSettingsMenuSelect ), this, m_projectSettings_menuItem->GetId());
	m_build_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnRunGameMenuSelect ), this, m_run_menuItem->GetId());
	m_build_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnRunStageMenuSelect ), this, m_runStage_menuItem->GetId());
	m_build_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnAbortMenuSelect ), this, m_abortRun_menuItem->GetId());
	m_build_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnDistributeMenuSelect ), this, m_dist_menuItem->GetId());
	m_help_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OOS3D_Engine::OnAboutMenuSelect ), this, m_about_menuItem->GetId());
	this->Connect( m_newProject_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnNewProjectMenuSelect ) );
	this->Connect( m_openProject_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnLoadProjectMenuSelect ) );
	this->Connect( m_saveProject_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnSaveProjectMenuSelect ) );
	this->Connect( m_play_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnRunStageMenuSelect ) );
	this->Connect( m_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAbortMenuSelect ) );
	this->Connect( m_view_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnViewToolSelect ) );
	this->Connect( m_select_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnSelectToolSelect ) );
	this->Connect( m_boxSelect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnBoxSelectToolSelect ) );
	this->Connect( m_move_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnMoveToolSelect ) );
	this->Connect( m_rotate_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnRotateToolSelect ) );
	this->Connect( m_scale_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnScaleToolSelect ) );
	this->Connect( m_terrain_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnSetTerrainToolSelect ) );
	this->Connect( m_addActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddActorToolSelect ) );
	this->Connect( m_addLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddLightToolSelect ) );
	this->Connect( m_addCamera_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddCameraToolSelect ) );
	this->Connect( m_effect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddEffectToolSelect ) );
	this->Connect( m_event_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddEventToolSelect ) );
	m_project_treeCtrl->Connect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( OOS3D_Engine::OnProjectTreeContextMenu ), NULL, this );
}

OOS3D_Engine::~OOS3D_Engine()
{
	// Disconnect Events
	this->Disconnect( m_newProject_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnNewProjectMenuSelect ) );
	this->Disconnect( m_openProject_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnLoadProjectMenuSelect ) );
	this->Disconnect( m_saveProject_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnSaveProjectMenuSelect ) );
	this->Disconnect( m_play_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnRunStageMenuSelect ) );
	this->Disconnect( m_stop_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAbortMenuSelect ) );
	this->Disconnect( m_view_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnViewToolSelect ) );
	this->Disconnect( m_select_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnSelectToolSelect ) );
	this->Disconnect( m_boxSelect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnBoxSelectToolSelect ) );
	this->Disconnect( m_move_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnMoveToolSelect ) );
	this->Disconnect( m_rotate_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnRotateToolSelect ) );
	this->Disconnect( m_scale_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnScaleToolSelect ) );
	this->Disconnect( m_terrain_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnSetTerrainToolSelect ) );
	this->Disconnect( m_addActor_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddActorToolSelect ) );
	this->Disconnect( m_addLight_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddLightToolSelect ) );
	this->Disconnect( m_addCamera_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddCameraToolSelect ) );
	this->Disconnect( m_effect_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddEffectToolSelect ) );
	this->Disconnect( m_event_tool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OOS3D_Engine::OnAddEventToolSelect ) );
	m_project_treeCtrl->Disconnect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( OOS3D_Engine::OnProjectTreeContextMenu ), NULL, this );

}

newProjectDialog::newProjectDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Project Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer21->Add( m_staticText4, 1, wxALL, 5 );

	m_projectName_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_projectName_textCtrl, 5, wxALL, 5 );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer20->Add( bSizer21, 2, wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );


	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_cancel_button, 0, wxALL, 5 );

	m_ok_button = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_ok_button, 0, wxALL, 5 );


	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer20 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newProjectDialog::OnCancelButtonClick ), NULL, this );
	m_ok_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newProjectDialog::OnOKButtonClick ), NULL, this );
}

newProjectDialog::~newProjectDialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newProjectDialog::OnCancelButtonClick ), NULL, this );
	m_ok_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newProjectDialog::OnOKButtonClick ), NULL, this );

}

newStageDialog::newStageDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Stage Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer21->Add( m_staticText4, 1, wxALL, 5 );

	m_stageName_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_stageName_textCtrl, 5, wxALL, 5 );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer20->Add( bSizer21, 2, wxEXPAND, 5 );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxHORIZONTAL );


	bSizer211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Stage Type  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer211->Add( m_staticText41, 1, wxALL, 5 );

	m_stageType_comboBox = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer211->Add( m_stageType_comboBox, 5, wxALL, 5 );


	bSizer211->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer20->Add( bSizer211, 2, wxEXPAND, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );


	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_cancel_button, 0, wxALL, 5 );

	m_ok_button = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_ok_button, 0, wxALL, 5 );


	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer20 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newStageDialog::OnCancelButtonClick ), NULL, this );
	m_ok_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newStageDialog::OnOKButtonClick ), NULL, this );
}

newStageDialog::~newStageDialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newStageDialog::OnCancelButtonClick ), NULL, this );
	m_ok_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newStageDialog::OnOKButtonClick ), NULL, this );

}

newScriptDialog::newScriptDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Script Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer21->Add( m_staticText4, 1, wxALL, 5 );

	m_scriptName_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_scriptName_textCtrl, 5, wxALL, 5 );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer20->Add( bSizer21, 2, wxEXPAND, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );


	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_cancel_button, 0, wxALL, 5 );

	m_ok_button = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_ok_button, 0, wxALL, 5 );


	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer20 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newScriptDialog::OnCancelButtonClick ), NULL, this );
	m_ok_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newScriptDialog::OnOKButtonClick ), NULL, this );
}

newScriptDialog::~newScriptDialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newScriptDialog::OnCancelButtonClick ), NULL, this );
	m_ok_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( newScriptDialog::OnOKButtonClick ), NULL, this );

}

importModelDialog::importModelDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );


	bSizer19->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer20->Add( m_staticText5, 0, wxALL, 5 );

	m_filePicker1 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer20->Add( m_filePicker1, 8, wxALL, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );

	m_importModels_checkBox = new wxCheckBox( this, wxID_ANY, wxT("Import Models"), wxDefaultPosition, wxDefaultSize, 0 );
	m_importModels_checkBox->SetValue(true);
	bSizer21->Add( m_importModels_checkBox, 4, wxALL, 5 );


	bSizer21->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer21, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer214;
	bSizer214 = new wxBoxSizer( wxHORIZONTAL );


	bSizer214->Add( 0, 0, 1, wxEXPAND, 5 );

	m_importTextures_checkBox = new wxCheckBox( this, wxID_ANY, wxT("Import Textures"), wxDefaultPosition, wxDefaultSize, 0 );
	m_importTextures_checkBox->SetValue(true);
	bSizer214->Add( m_importTextures_checkBox, 4, wxALL, 5 );


	bSizer214->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer214, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxHORIZONTAL );


	bSizer211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_importArmature_checkBox = new wxCheckBox( this, wxID_ANY, wxT("Import Armatures"), wxDefaultPosition, wxDefaultSize, 0 );
	m_importArmature_checkBox->SetValue(true);
	bSizer211->Add( m_importArmature_checkBox, 4, wxALL, 5 );


	bSizer211->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer211, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer212;
	bSizer212 = new wxBoxSizer( wxHORIZONTAL );


	bSizer212->Add( 0, 0, 1, wxEXPAND, 5 );

	m_importAnimation_checkBox = new wxCheckBox( this, wxID_ANY, wxT("Import Animations"), wxDefaultPosition, wxDefaultSize, 0 );
	m_importAnimation_checkBox->SetValue(true);
	bSizer212->Add( m_importAnimation_checkBox, 4, wxALL, 5 );


	bSizer212->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer212, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer213;
	bSizer213 = new wxBoxSizer( wxHORIZONTAL );


	bSizer213->Add( 0, 0, 1, wxEXPAND, 5 );

	m_importScene_checkBox = new wxCheckBox( this, wxID_ANY, wxT("Import Scene As Stage"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer213->Add( m_importScene_checkBox, 4, wxALL, 5 );


	bSizer213->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer213, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );


	bSizer35->Add( 0, 0, 2, wxEXPAND, 5 );

	m_cancel_button = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_cancel_button, 1, wxALL|wxEXPAND, 5 );

	m_import_button = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_import_button, 1, wxALL|wxEXPAND, 5 );


	bSizer34->Add( bSizer35, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer34, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer19 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_cancel_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( importModelDialog::OnCancelButtonClick ), NULL, this );
	m_import_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( importModelDialog::OnOKButtonClick ), NULL, this );
}

importModelDialog::~importModelDialog()
{
	// Disconnect Events
	m_cancel_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( importModelDialog::OnCancelButtonClick ), NULL, this );
	m_import_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( importModelDialog::OnOKButtonClick ), NULL, this );

}
