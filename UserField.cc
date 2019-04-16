#include "UserField.hh"

UserField::UserField(G4double voltage, G4double rmin, G4double rmax, G4double det_length)
{ 
 fvoltage=voltage;
 frmin=rmin;
 frmax=rmax;
 fdet_length=det_length;
} 

UserField::~UserField()
{
}

void UserField::GetFieldValue(const G4double Point[4], G4double *pField) const
{
// G4double rmin = 1. * mm;
// G4double rmax = 30. * mm;
// G4double Uvolt= 20. * volt;
 G4double radius=0., fieldMag=0., fi=0.;
 G4ThreeVector RadField;
 
 if ((Point[2]>-fdet_length)&&(Point[2]<fdet_length))
 {
 radius=powf((powf(Point[0],2.)+powf(Point[1],2.)),0.5);
  if ((radius>frmin)&&(radius<frmax))
  {
   fieldMag = fvoltage/(radius*(std::log(frmin/frmax)));
   fi=atan2(Point[1],Point[0]);   
   RadField = G4ThreeVector(fieldMag*cos(fi),fieldMag*sin(fi),0.);   
  }
  else
  {
   RadField = G4ThreeVector(0.,0.,0.);   
  }
 }
 else
 {
  RadField = G4ThreeVector(0.,0.,0.); 
 }

 pField[0]=0.;
 pField[1]=0.;
 pField[2]=0.;
 pField[3]=RadField.x();
 pField[4]=RadField.y();
 pField[5]=RadField.z();
}
