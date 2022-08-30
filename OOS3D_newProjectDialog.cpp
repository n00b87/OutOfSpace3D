#include "OOS3D_newProjectDialog.h"

#include <wx/msgdlg.h>


OOS3D_newProjectDialog::OOS3D_newProjectDialog( wxWindow* parent )
:
newProjectDialog( parent )
{
    project_name = _("Untitled");

    m_projectName_textCtrl->SetValue(project_name);
    exit_status = NEWPROJECT_EXIT_STATUS_CANCEL;
}

void OOS3D_newProjectDialog::OnCancelButtonClick(wxCommandEvent& event)
{
    exit_status = NEWPROJECT_EXIT_STATUS_CANCEL;
    Close();
}

void OOS3D_newProjectDialog::OnOKButtonClick(wxCommandEvent& event)
{
    if(m_projectName_textCtrl->GetValue().Trim().compare(_(""))==0)
    {
        wxMessageBox(_("Missing Project Name"));
        return;
    }
    exit_status = NEWPROJECT_EXIT_STATUS_OK;
    project_name = m_projectName_textCtrl->GetValue();
    Close();
}
