#include "MyField.hh"

//#define SU *mm

MyField::MyField(): myEMfield(0), myEquation(0), myStepper(0), myntgrDriver(0), myChordFinder(0), myFieldManager(0),
                    globEMfield(0), globEquation(0), globStepper(0), globntgrDriver(0), globChordFinder(0), globFieldManager(0)
//MyField::MyField()::G4UniformElectricField(G4ThreeVector())
{
// Local field
// myEMfield      = new G4UniformElectricField(G4ThreeVector(0.0,50000.0*kilovolt/cm,0.0));
 myEMfield      = new UserField(2.*powf(10.,9.) * volt, 1. * mm, 30. * mm, 50. * mm);
 myEquation     = new G4EqMagElectricField(myEMfield);
 myStepper      = new G4ClassicalRK4(myEquation,8);
 myntgrDriver   = new G4MagInt_Driver(0.001*mm, myStepper, myStepper->GetNumberOfVariables());
 myChordFinder  = new G4ChordFinder(myntgrDriver);
 myFieldManager = new G4FieldManager(myEMfield,myChordFinder,true);

// Total field
 globFieldManager = G4TransportationManager::GetTransportationManager()->GetFieldManager();
 globEMfield      = new G4UniformElectricField(G4ThreeVector(0.0,-50000.0*kilovolt/cm,0.0));
 globEquation     = new G4EqMagElectricField(globEMfield);
 globStepper      = new G4ClassicalRK4(globEquation,8);
 globntgrDriver   = new G4MagInt_Driver(0.001*mm, globStepper, globStepper->GetNumberOfVariables());
 globChordFinder  = new G4ChordFinder(globntgrDriver);
 globFieldManager->SetDetectorField(globEMfield);
 globFieldManager->SetChordFinder(globChordFinder);
}

MyField::~MyField()
{
 delete myChordFinder;  //myChordFinder= nullptr;
 delete myStepper;      //myStepper = nullptr;
 delete myEquation;     //myEquation = nullptr;
 delete myEMfield;      //myEMfield = nullptr;

 delete globChordFinder;  //globChordFinder= nullptr;
 delete globStepper;      //globStepper = nullptr;
 delete globEquation;     //globEquation = nullptr;
 delete globEMfield;      //globEMfield = nullptr;

}

