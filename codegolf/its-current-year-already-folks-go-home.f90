! On most new-years challenges when it is currently not the corresponding year of the challenge, It says this in the front.
!
! It's [current year] already, folks, go home.
!
! You have to output this text with the current year substituted.
!
! I/O
! Input: None.
!
! Output: It's [current year] already, folks, go home.

program main
    implicit none
    integer :: dt(8)

    call date_and_time(values=dt)
    print "(a, i4, a)", "It's ", dt(1), " already, folks, go home."
end program main
