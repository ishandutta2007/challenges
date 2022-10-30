! Task
! Given a non-negative integer n, evaluate the factorial n!.
!
! Rules
! All default I/O methods are allowed.
! Standard loopholes are forbidden.
! Built-ins are allowed.
! There is no time or memory limit.
! Giving imprecise or incorrect results for large inputs due to the limit of the native number format is fine, as long as the underlying algorithm is correct.
! Specifically, it is not allowed to abuse the native number type to trivialize the challenge, which is one of the standard loopholes.
! This is code-golf. Shortest code in bytes wins, but feel free to participate in various esolangs (especially the ones hindered by the restrictions of the former challenge).
! Test cases
! 0! = 1
! 1! = 1
! 2! = 2
! 3! = 6
! 4! = 24
! 5! = 120
! 6! = 720
! 7! = 5040
! 8! = 40320
! 9! = 362880
! 10! = 3628800
! 11! = 39916800
! 12! = 479001600

program main
    implicit none
    integer n

    do n = 0, 32
        print *, n, fact(n)
    enddo

contains
    integer(kind=16) function fact(n)
        implicit none
        integer, intent(in) :: n
        integer :: i

        if (n < 0) then
            fact = 0
            return
        endif

        fact = 1
        do i = 1, n
            fact = fact * i
        end do
    end function fact
end program main
