#ifndef PLENUMPRESSURE_H
#define PLENUMPRESSURE_H

#include "IntegratedBC.h"

//Forward Declarations
class PlenumPressure;

template<>
InputParameters validParams<PlenumPressure>();

class PlenumPressure : public IntegratedBC
{
public:

  PlenumPressure(const std::string & name, InputParameters parameters);

  virtual ~PlenumPressure(){}

  virtual void initialSetup();

  virtual void residualSetup();

protected:

  virtual Real computeQpResidual();

  Real _n0; // The initial number of moles of gas.

  const int _component;

  const Real _initial_pressure;

  PostprocessorValue * const _material_input;

  const Real _R;

  const Real & _temperature;

  const Real & _volume;

  const Real _startup_time;

  PostprocessorValue * const _initial_moles;
  PostprocessorValue * const _output;

  Real _my_value;

};

#endif //PLENUMRESSURE_H
