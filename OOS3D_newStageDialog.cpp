#include "OOS3D_newStageDialog.h"

#include <wx/msgdlg.h>

OOS3D_newStageDialog::OOS3D_newStageDialog( wxWindow* parent )
:
newStageDialog( parent )
{
    stage_name = _("Untitled Stage");
    exit_status = NEWSTAGE_EXIT_STATUS_CANCEL;

    m_stageType_comboBox->Clear();
    m_stageType_comboBox->Append(_("3D Stage"));
    m_stageType_comboBox->Append(_("2D Stage"));
}

void OOS3D_newStageDialog::OnCancelButtonClick( wxCommandEvent& event )
{
    exit_status = NEWSTAGE_EXIT_STATUS_CANCEL;
    Close();
}

void OOS3D_newStageDialog::OnOKButtonClick( wxCommandEvent& event )
{
    exit_status = NEWSTAGE_EXIT_STATUS_OK;

    if(m_stageName_textCtrl->GetValue().Trim().compare(_(""))==0)
    {
        wxMessageBox(_("Missing Stage Name"));
        return;
    }

    stage_name = m_stageName_textCtrl->GetValue();
    stage_type = m_stageType_comboBox->GetSelection();

    Close();
}
