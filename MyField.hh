#ifndef CPROJECT_FIELD_HH
#define CPROJECT_FIELD_HH

#include "UserField.hh"

#include "G4SystemOfUnits.hh"

#include "G4UniformElectricField.hh"
#include "G4UniformMagField.hh"
#include "G4MagneticField.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "G4EquationOfMotion.hh"
#include "G4EqMagElectricField.hh"
#include "G4Mag_UsualEqRhs.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4MagIntegratorDriver.hh"
#include "G4ChordFinder.hh"

#include "G4ClassicalRK4.hh"

class MyField
{
 public:

//  G4ElectricField* myEMfield;
  UserField* myEMfield;

  G4EqMagElectricField* myEquation;
  G4MagIntegratorStepper* myStepper;
  G4MagInt_Driver* myntgrDriver;
  G4ChordFinder* myChordFinder; 
  G4FieldManager* myFieldManager;

  G4ElectricField* globEMfield;
  G4EqMagElectricField* globEquation;
  G4MagIntegratorStepper* globStepper;
  G4MagInt_Driver* globntgrDriver;
  G4ChordFinder* globChordFinder; 
  G4FieldManager* globFieldManager;

  MyField();
  ~MyField();
};
 
#endif //CPROJECT_FIELD_HH