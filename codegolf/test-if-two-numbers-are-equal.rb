#!/usr/bin/env ruby

=begin

Challenge

    Input two integers.
    Integer I/O must be decimal.
    If the integers are equal, output a truthy value.
    Otherwise, output a falsy value.

Clarifications

    You will never receive non-integer inputs.
    You will never receive an input that is outside the bounds [-2³¹, 2³¹).

Rules

    Standard loopholes are disallowed.
    This is code-golf. Shortest answer wins, but will not be selected.

=end

def equal(x, y)
  return x == y
end

raise unless equal(1, 1)
raise unless equal(2, 2)
raise unless equal(3, 3)
raise unless !equal(1, 2)
raise unless !equal(2, 1)
raise unless !equal(350, 34)
