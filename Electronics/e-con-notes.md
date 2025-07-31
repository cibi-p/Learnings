# Electronics

## Basic circuit elements
1. Resisor
1. Inductor
1. Capacitor

### Resistor
Property of material to oppose the flow of electrons through the material

1. $R=\frac{\rho l}{A}$

    $\rho$ --> Resistivity\
    l --> Lenght of the conductor\
    A --> Area of cross section

1. Accroding to ohms law, $V=IR$ Watts

1. Power ansprned of by resistor $P=VI=I^2 R$
1. Energy lost in the resistance in form of heat $E=I^2Rt$ Joules

- Linear device
- ohms law, V=IR
- before using restitor know, Actual Resistance, power rating, resistor tolerance, thermal coefficient,

### Inductance
Property of material which opposes any change of magnitude or direction of current passing through the conductor. Energy stored in the inductor is in the form of magnetic field. unit is henry

1. Voltage of the inductor is $V=L\frac{di}{dt}$
1. Power = P=VI=$P=Li\frac{di}{dt}$ watts
1. Energy stored $E=\frac{1}{2}Li^2$ Joules
1. Inductive Reactance = $X_L = 2\pi fL$

Here voltage is leading current in phasor diagram by 90&deg;

### Capacitance
Capacbility of element to store electric charge within it. unit is Farad

1. Current inside capacitor is $I=C\frac{dV_c}{dt}$ Amphere
1. Power $P=VI=VC\frac{dV_c}{dt}$ Watts
1. Energy $E=\frac{1}{2}CV^2$ Joules
1. Capacitance $C=\frac{\epsilon A}{d}$, where $\epsilon$ is permittivity, d is distanc between plates, A is area of plates
1. Capacitance $C=\frac{Q}{V}$, Q is charge
1. Capacitive reactance, $X_C=\frac{1}{2\pi fC}$ $\Omega$

Here Current is leading voltage in phasor diagram by 90&deg;


## MOSFET
- Metal Oxide Semiconductor Field Effect Transistor
![](https://www.lesics.com/Working-of-Transistors/mosfet.jpg)

![](https://www.electricaltechnology.org/wp-content/uploads/2021/06/MOSFET-Working-Types-Operation-Advantages-and-Applications.png)
 - Enhancement Mode (off at Zero gate-source voltage)
 - Deplition Mode (on at zero gate-source voltage)

## Voltage regulators  
The below diagram shows the 5 voltage regulator, it convert the 6-35V to 5V constant. (78xx here xx represert the output voltage of the regulate). We can connect the capactiter parallel in the ouput to avoid fluctuation or to get constant voltage.  
LM7805 is the voltage regulator name, here `LM78` represent regulator series. ex: LM7805 produce 5V, 0.5A, L7805 --> 5V,1A, L78S05 --> 5V, 2A  

7905 produces the negative 5volts

If you want to reduce the current you need to use DC-DC step down converter (buck converter)
![](https://components101.com/sites/default/files/component_pin/7805-Voltage-Regulator-Pinout.png)

## Buck Converter (https://www.youtube.com/watch?v=W6NOV6b8kxs)
we reduce the AC voltage using transformer, similary for DC we use Buck converter  

https://electronics-fun.com/buck-converter/
![](https://electronics-fun.com/wp-content/uploads/2021/11/Buck-Boost-circuit-diagram-768x435.png)

## LDO Basics: Dropout voltage
Low Dropout or LDO regulator is a linear voltage regulator that can retulate even weh teh supply is close to the ouput
example IC: TLV760

$V_{OUT} = V_{IN} - V_{DO}$

$V_{DO}$ is the voldate drop or the minimum voltage difference between $V_{IN}$ and $V_{OUT}$ need for regulation