//
// Pengo Project
//
// Copyright (c) 2015 Penlook Development Team
//
// --------------------------------------------------------------------
//
// This program is free software: you can redistribute it and/or
// modify it under the terms of the GNU Affero General Public License
// as published by the Free Software Foundation, either version 3
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with this program.
// If not, see <http://www.gnu.org/licenses/>.
//
// --------------------------------------------------------------------
//
// Authors:
//     Loi Nguyen       <loint@penlook.com>

// sum(int a, int b, int c)

.globl  sum
	.type  sum, @function
sum:
	pushq  %rbp
	movq  %rsp, %rbp
	movl  %edi, -4(%rbp)
	movl  %esi, -8(%rbp)
	movl  -8(%rbp), %eax
	movl  -4(%rbp), %edx
	addl  %edx, %eax
	addl  $3, %eax
	popq  %rbp
	ret
