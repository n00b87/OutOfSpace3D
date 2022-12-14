#ifndef __OutOfSpace_EngineimportModelDialog__
#define __OutOfSpace_EngineimportModelDialog__

/**
@file
Subclass of importModelDialog, which is generated by wxFormBuilder.
*/

#include "OOS3D_Engine.h"

//// end generated include

#define IMPORTMODEL_EXIT_STATUS_CANCEL   0
#define IMPORTMODEL_EXIT_STATUS_OK       1

/** Implementing importModelDialog */
class OOS3D_importModelDialog : public importModelDialog
{
	protected:
		// Handlers for importModelDialog events.
		void OnCancelButtonClick( wxCommandEvent& event );
		void OnOKButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		OOS3D_importModelDialog( wxWindow* parent );

		int exit_status;

		wxFileName asset_fname;

		bool animation_flag;
		bool armature_flag;
		bool texture_flag;
		bool scene_flag;

	//// end generated class members


};

#endif // __OutOfSpace_EngineimportModelDialog__
