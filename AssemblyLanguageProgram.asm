; MASM.asm - Exam Scores
; Ayush Das

INCLUDE Irvine32.inc
.data
AL DWORD
printScores BYTE "Score = ", 0
printGrade BYTE "Grade = ", 0

.code
main PROC
L0:
	cmp 90, AL                ; if AL >= 90, grade is A
	ja next
	mov eax, A
.string "A"
L1:
	cmp 80, AL                ; if AL >= 80, grade is B
	ja next
	mov ebx, B
.string "B"
L2:
	cmp 70, AL                ; if AL >= 70, grade is B
	ja next
	mov ecx, C
.string "C"
L3:
	cmp 60, AL                ; if AL >= 60, grade is D
	ja next
	mov edx, D
.string "D"
L4:
	cmp AL, 60                ; if AL < 60, grade is E
	ja next
	mov eex, E
.string "E"
L5:
	mov edx, OFFSET printScores
	mov edx, OFFSET printGrade
invoke ExitProcess, 0

main endp
end main