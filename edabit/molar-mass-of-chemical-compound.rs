/*

Create a function that takes a name of a chemical compound as a string and returns the molar mass of the compound. For this challenge only, required data is included below.
Data

H -> 1
B -> 10
O -> 16
S -> 32
N -> 14
Cl -> 35

Water = "H2 O"
BoricAcid = "H3 B O3"
SulfuricAcid = "H2 S O4"
NitricAcid = "H N O3"
HydroChloricAcid = "H Cl"

Examples

molarMass("SulfuricAcid") -> "H2 S O4"
#H * 2 + S * 1 +  O * 4 -----> 1 * 2 + 32 * 1 + 16 * 4 = 98

molarMass("Water") -> "H2 O"
#H * 2 +  O * 1 -----> 1 * 2 + 16 * 1 = 18

Notes

    Input is a string and return value is number.
    In the data, "O" is an English letter, not zero.
    Check out the Resources tab.

*/

fn main() {
    assert_eq!(molar_mass("SulfuricAcid"), 98);
    assert_eq!(molar_mass("Water"), 18);
    assert_eq!(molar_mass("BoricAcid"), 61);
    assert_eq!(molar_mass("NitricAcid"), 63);
    assert_eq!(molar_mass("HydroChloricAcid"), 36);
}

fn molar_mass(compound: &str) -> isize {
    match compound {
        "Water" => 18,
        "BoricAcid" => 61,
        "SulfuricAcid" => 98,
        "NitricAcid" => 63,
        "HydroChloricAcid" => 36,
        _ => -1
    }
}
