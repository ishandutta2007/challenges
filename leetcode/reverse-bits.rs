// Reverse bits of a given 32 bits unsigned integer.

fn main() {
    println!("{:032b}", reverse_bits(0b00000010100101000001111010011100));
    println!("{:032b}", reverse_bits(0b11111111111111111111111111111101));
}

fn reverse_bits(x: u32) -> u32 {
    let mut v = x;
    v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
    v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
    v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
    v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
    v = ( v >> 16             ) | ( v               << 16);
    v
}
