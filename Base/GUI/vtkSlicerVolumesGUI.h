// .NAME vtkSlicerVolumesGUI 
// .SECTION Description
// Main Volumes GUI and mediator methods for slicer3. 


#ifndef __vtkSlicerVolumesGUI_h
#define __vtkSlicerVolumesGUI_h

#include "vtkSlicerBaseGUIWin32Header.h"
#include "vtkSlicerModuleGUI.h"

#include "vtkSlicerVolumesLogic.h"
#include "vtkMRMLVolumeNode.h"

#include "vtkSlicerNodeSelectorWidget.h"
#include "vtkSlicerVolumeDisplayWidget.h"

class vtkKWPushButton;
class vtkKWLoadSaveButtonWithLabel;
class vtkKWLoadSaveButton;
class vtkKWEntryWithLabel;
class vtkSlicerModuleCollapsibleFrame;

// Description:
// This class implements Slicer's Volumes GUI
//
class VTK_SLICER_BASE_GUI_EXPORT vtkSlicerVolumesGUI : public vtkSlicerModuleGUI
{
 public:
    // Description:
    // Usual vtk class functions
    static vtkSlicerVolumesGUI* New (  );
    vtkTypeRevisionMacro ( vtkSlicerVolumesGUI, vtkSlicerModuleGUI );
    void PrintSelf (ostream& os, vtkIndent indent );
    
    // Description:
    // Get methods on class members (no Set methods required)
    vtkGetObjectMacro ( LoadVolumeButton, vtkKWLoadSaveButtonWithLabel );

    vtkGetObjectMacro ( Logic, vtkSlicerVolumesLogic );
    vtkGetObjectMacro ( VolumeNode, vtkMRMLVolumeNode );

    vtkGetStringMacro ( SelectedVolumeID);
    vtkSetStringMacro ( SelectedVolumeID );

    vtkGetObjectMacro (HelpFrame, vtkSlicerModuleCollapsibleFrame );
    vtkGetObjectMacro (LoadFrame, vtkSlicerModuleCollapsibleFrame );
    vtkGetObjectMacro (DisplayFrame, vtkSlicerModuleCollapsibleFrame );
    vtkGetObjectMacro (SaveFrame, vtkSlicerModuleCollapsibleFrame );

    vtkGetObjectMacro ( VolumeDisplayWidget, vtkSlicerVolumeDisplayWidget );

    // Description:
    // API for setting VolumeNode, VolumeLogic and
    // for both setting and observing them.
    void SetModuleLogic ( vtkSlicerVolumesLogic *logic )
        { this->SetLogic ( vtkObjectPointer (&this->Logic), logic ); }
    void SetAndObserveModuleLogic ( vtkSlicerVolumesLogic *logic )
        { this->SetAndObserveLogic ( vtkObjectPointer (&this->Logic), logic ); }

    // Description:
    // This method builds the Volumes module GUI
    virtual void BuildGUI ( );

    // Description:
    // Add/Remove observers on widgets in the GUI
    virtual void AddGUIObservers ( );
    virtual void RemoveGUIObservers ( );


    // Description:
    // Class's mediator methods for processing events invoked by
    // either the Logic, MRML or GUI.
    virtual void ProcessLogicEvents ( vtkObject *caller, unsigned long event, void *callData );
    virtual void ProcessGUIEvents ( vtkObject *caller, unsigned long event, void *callData );
    virtual void ProcessMRMLEvents ( vtkObject *caller, unsigned long event, void *callData );
    
    // Description:
    // Describe behavior at module startup and exit.
    virtual void Enter ( );
    virtual void Exit ( );

 protected:
    vtkSlicerVolumesGUI ( );
    virtual ~vtkSlicerVolumesGUI ( );
    
    char *SelectedVolumeID;

    // Module logic and mrml pointers
    vtkSlicerVolumesLogic *Logic;
    vtkMRMLVolumeNode *VolumeNode;

    // Widgets for the Volumes module
    vtkKWLoadSaveButtonWithLabel *LoadVolumeButton;
    vtkKWEntryWithLabel  *NameEntry;
    vtkKWMenuButtonWithLabel *CenterImageMenu;
    vtkKWCheckButton *LabelMapCheckButton;
    vtkKWPushButton *ApplyButton;

    vtkSlicerModuleCollapsibleFrame *HelpFrame;
    vtkSlicerModuleCollapsibleFrame *LoadFrame;
    vtkSlicerModuleCollapsibleFrame *DisplayFrame;
    vtkSlicerModuleCollapsibleFrame *SaveFrame;

    vtkSlicerNodeSelectorWidget* VolumeSelectorWidget;
    vtkKWLoadSaveButton *SaveVolumeButton;
    vtkSlicerVolumeDisplayWidget *VolumeDisplayWidget;

 private:
    vtkSlicerVolumesGUI ( const vtkSlicerVolumesGUI& ); // Not implemented.
    void operator = ( const vtkSlicerVolumesGUI& ); //Not implemented.
};

#endif
