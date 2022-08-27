#include "OOS3D_newProjectDialog.h"


OOS3D_newProjectDialog::OOS3D_newProjectDialog( wxWindow* parent )
:
newProjectDialog( parent )
{
    project_name = _("Untitled");

    m_projectName_textCtrl->SetValue(project_name);
}

void OOS3D_newProjectDialog::OnCancelButtonClick(wxCommandEvent& event)
{
    Close();
}

void OOS3D_newProjectDialog::OnOKButtonClick(wxCommandEvent& event)
{
    Close();
}
