#!/usr/bin/python
#
# Pengo Project
#
# Copyright (c) 2015 Penlook Development Team
#
# --------------------------------------------------------------------
#
# This program is free software: you can redistribute it and/or
# modify it under the terms of the GNU Affero General Public License
# as published by the Free Software Foundation, either version 3
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public
# License along with this program.
# If not, see <http://www.gnu.org/licenses/>.
#
# --------------------------------------------------------------------
#
# Authors:
#     Loi Nguyen       <loint@penlook.com>

app_structure = """
[
	build
	[
		app
		[
			config { nginx.conf },
			controller { .keep },
			model { .keep },
			service { .keep }
		]
		development
		[
			
		] { Makefile, build.sh }
		production
		[
			config { gcc, make, nginx }
			module { config, ngx_http_app_module.cpp }
			{ build.sh, config.sh }
		]
	]
]
[
	controller { index.cpp }
]
[
	library
	[
		inc { .keep },
		src { .keep }
	]
]
[
	model { .keep }
]
[
	service { .keep }
]
[
	view
	[
		index { index.html }
	]
	{ layout.html }
]
"""