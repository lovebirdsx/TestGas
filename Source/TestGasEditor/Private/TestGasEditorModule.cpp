#include "TestGasEditorModule.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FTestGasEditor, TestGasEditor);

void FTestGasEditor::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("TestGasEditor module has started!"));
}

void FTestGasEditor::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("TestGasEditor module has shut down!"));
}
