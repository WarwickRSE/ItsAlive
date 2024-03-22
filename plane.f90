MODULE move_plane
  IMPLICIT NONE

  TYPE position
    REAL :: x, y
  END TYPE position

  INTEGER, PARAMETER :: nx =100, ny =100
  REAL, PARAMETER :: lx = 1000.0, ly=1000.0
  REAL, PARAMETER :: dx = lx/REAL(nx), dy=ly/REAL(ny)

  INTEGER, DIMENSION(:,:), ALLOCATABLE :: spatial_grid

  CONTAINS

  FUNCTION generate_trajectory(speed) RESULT(answer)
    REAL, INTENT(IN) :: speed
    TYPE(position), DIMENSION(:), ALLOCATABLE :: answer
    INTEGER :: itime

    ALLOCATE(answer(10))
    DO itime=0, 9
      answer(itime+1) = position(speed * REAL(itime), speed * REAL(itime))
    END DO
  END FUNCTION generate_trajectory

END MODULE move_plane

PROGRAM plane
  USE move_plane
  IMPLICIT NONE
  TYPE(position), DIMENSION(:), ALLOCATABLE :: pos
  LOGICAL, DIMENSION(:,:), ALLOCATABLE :: visited
  INTEGER :: ix, iy, ipos, iplane

  ALLOCATE(spatial_grid(nx,ny))
  ALLOCATE(visited(nx,ny), SOURCE=.FALSE.)
  spatial_grid=0

  DO iplane = 1, 3
    pos = generate_trajectory(7.5*iplane)
    DO ipos = 1, SIZE(pos)
      ix = FLOOR(pos(ipos)%x/dx)+1
      iy = FLOOR(pos(ipos)%y/dy)+1
      IF (ix >0 .AND. ix <=nx .AND. iy >0 .AND. iy <=ny) THEN
        IF (.NOT. visited(ix,iy)) THEN
          spatial_grid(ix,iy) = spatial_grid(ix,iy) + 1
          visited(ix,iy) = .TRUE.
        END IF
      END IF
    END DO
    visited = .FALSE.
  END DO

  PRINT *, "Minimum of array " , MINVAL(spatial_grid)
  PRINT *, "Maximum of array " , MAXVAL(spatial_grid)

END PROGRAM plane
