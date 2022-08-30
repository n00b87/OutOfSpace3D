#ifndef __OutOfSpace_EngineimportModelDialog__
#define __OutOfSpace_EngineimportModelDialog__

/**
@file
Subclass of importModelDialog, which is generated by wxFormBuilder.
*/

#include "OOS3D_Engine.h"

//// end generated include

/** Implementing importModelDialog */
class OutOfSpace_EngineimportModelDialog : public importModelDialog
{
	protected:
		// Handlers for importModelDialog events.
		void OnCancelButtonClick( wxCommandEvent& event );
		void OnOKButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		OutOfSpace_EngineimportModelDialog( wxWindow* parent );
	//// end generated class members


};

#endif // __OutOfSpace_EngineimportModelDialog__
