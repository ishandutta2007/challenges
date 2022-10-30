! Who doesn't love the Pythagorean theorem a^2+b^2=c^2?
! Write the shortest method you can in any language that takes in value a and b and prints out
! "The hypotenuse of this right triangle is c."
! Keep c to only three decimal places.


subroutine pythagorean(a, b)
    real, intent(in) :: a
    real, intent(in) :: b

    print *, "The hypotenuse of this right triangle is", hypot(a, b)
end subroutine

program main
    implicit none

    call pythagorean(3.0, 4.0)
    call pythagorean(5.0, 12.0)
    call pythagorean(56.0, 67.0)
end program
