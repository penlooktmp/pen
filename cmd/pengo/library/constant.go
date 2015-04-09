package library

var (
	ANNOTATION_CONTROLLER           =   "@Controller"
	ANNOTATION_CONTROLLER_PROPERTY  =   []string {
											"@Route",
											"@Method",
											"@Template",
											"@Error",
											"@Pick",
											"@Rest",
											"@Less",
											"@Dart",
											"@Test",
										}
	ANNOTATION_MODEL      			=   "@Model"
	ANNOTATION_MODEL_TYPE			=	[] string {
											"@Table",
											"@Document",
											"@Graph",
										}
	ANNOTATION_MODEL_PROPERTY		=   [] string {
											"@Type",
											"@Server",
											"@Port",
											"@Database",
											"@File",
											"@Charset",
											"@Test",
										}
	ANNOTATION_LIBRARY				=   "@Library"
	ANNOTATION_LIBRARY_PROPERTY		=   [] string {
											"@Export",
										}


)