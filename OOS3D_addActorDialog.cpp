#include "OOS3D_addActorDialog.h"

OOS3D_addActorDialog::OOS3D_addActorDialog( wxWindow* parent )
:
addActorDialog( parent )
{
    exit_status = ADDACTOR_EXIT_STATUS_CANCEL;

    m_models_comboBox->SetSelection(0);
    m_hitBox_comboBox->SetSelection(0);
    m_textures_comboBox->SetSelection(0);

    model_index = 0;
    hitbox_index = 0;
    texture_index = 0;
}

void OOS3D_addActorDialog::OnCancelButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnCancelButtonClick
    exit_status = ADDACTOR_EXIT_STATUS_CANCEL;
    Close();
}

void OOS3D_addActorDialog::OnAddActorButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnAddActorButtonClick
    actor_id = m_actorID_textCtrl->GetValue();
    model = m_models_comboBox->GetValue();
    texture = m_textures_comboBox->GetValue();
    hitbox = m_hitBox_comboBox->GetValue();
    model_index = m_models_comboBox->GetSelection();
    hitbox_index = m_hitBox_comboBox->GetSelection();
    texture_index = m_textures_comboBox->GetSelection();
    exit_status = ADDACTOR_EXIT_STATUS_OK;
    Close();
}

void OOS3D_addActorDialog::addModel(wxString model_option)
{
    m_models_comboBox->Append(model_option);
    m_hitBox_comboBox->Append(model_option);
}

void OOS3D_addActorDialog::addTexture(wxString texture_option)
{
    m_textures_comboBox->Append(texture_option);
}
