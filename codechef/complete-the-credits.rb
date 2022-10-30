#!/usr/bin/env ruby

=begin

In Uttu's college, a semester is said to be a:

Overload semester if the number of credits taken >65.
Underload semester if the number of credits taken <35.
Normal semester otherwise
Given the number of credits X taken by Uttu, determine whether the semester is Overload, Underload or Normal.

Input Format
The first line will contain T - the number of test cases. Then the test cases follow.
The first and only of each test case contains a single integer X - the number of credits taken by Uttu.
You may print each character of Overload, Underload and Normal in uppercase or lowercase (for example, ovErLoAd, oVERlOAD, OVERLOAD will be considered identical).

Output Format
For each test case, output Overload, Underload or Normal depending upon the number of credits taken by Uttu.

Constraints
1≤T≤100
1≤X≤100

=end

def load(x)
  case x
  when 66..100
    return "Overload"
  when 35..65
    return "Normal"
  when 0..34
    return "Underload"
  else
    return "Invalid"
  end
end

raise unless load(65) == "Normal"
raise unless load(80) == "Overload"
raise unless load(23) == "Underload"
raise unless load(58) == "Normal"
