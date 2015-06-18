
import os,sys,string
from builder import TemplateBuilder

app_structure = """
[build]
[controller{index.cpp}]
[library[inc{.keep},src{.keep}]]
[view
	[index{index.html}],
	{layout.html}
]
{index.html}
"""

def generateApplication():
	text = string.replace(template_file.read(), " ","")
	tb =TemplateBuilder(text, "./")