#include <wx/filepicker.h>
#include <wx/checkbox.h>

#include "OOS3D_ImportModelDialog.h"

OOS3D_importModelDialog::OOS3D_importModelDialog( wxWindow* parent )
:
importModelDialog( parent )
{
    exit_status = IMPORTMODEL_EXIT_STATUS_CANCEL;
}

void OOS3D_importModelDialog::OnCancelButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnCancelButtonClick

    exit_status = IMPORTMODEL_EXIT_STATUS_CANCEL;
    Close();
}

void OOS3D_importModelDialog::OnOKButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnOKButtonClick

    asset_fname = m_asset_filePicker->GetFileName();

    animation_flag = m_importAnimation_checkBox->GetValue();
    armature_flag = m_importArmature_checkBox->GetValue();
    texture_flag = m_importTextures_checkBox->GetValue();
    scene_flag = m_importScene_checkBox->GetValue();

    exit_status = IMPORTMODEL_EXIT_STATUS_OK;
    Close();
}
