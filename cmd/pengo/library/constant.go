package library

// Application mode
var (
	MODE_DEVELOPMENT                = 0
	MODE_PRODUCTION                 = 1
)

// Annotation
var (
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

	ANNOTATION_LIBRARY_PROPERTY		=   [] string {
											"@Export",
										}

)

// Compile pattern
var (
	// Annotation
	PATTERN_ANNOTATION              =   "^\\@[A-Z]{1}[a-zA-Z0-9]+[\\s]+[\\w\\/\\:\"\\s]+"

	// Action syntax
	PATTERN_FUNCTION_DEFINE         =   "^[A-Z]{1}[a-zA-Z0-9\\s]+\\((|([a-zA-Z0-9\\s,]+))\\)\\s+\\{"

	// Method of current context
	PATTERN_FUNCTION_CALL           =   "\\@[A-Z]"

	// Controller filename
	PATTERN_FILENAME_CONTROLLER     =   "[a-z_]+\\.go"

	// Template Variable
	PATTERN_VARIABLE_TEMPLATE       =   "([\t]+)\\$[a-z\\s]+\\=[\\s]+"

	// Context variable
	PATTERN_VARIABLE_CONTEXT        =   "([\t]+)\\@\\@[a-z]"

	// Model function
	PATTERN_MODEL_FUNCTION          =   "\\#[A-Z]{1}[a-zA-Z0-9]+\\((|[a-zA-Z0-9,\\s\\&]+)\\)"

	// Model entity
	PATTERN_MODEL_ENTITY            =   "\\#[a-z]+\\[\"[a-zA-Z]+\"\\]"

	// Go method
	PATTERN_GO_METHOD				=   "\\[A-Z]{1}[a-zA-Z0-9\\s]+\\((|([a-zA-Z0-9\\s,]+))\\)"

	// C function
	PATTERN_C_FUNCTION				=   "\\~[A-Z]{1}[a-zA-Z0-9\\s]+\\((|([a-zA-Z0-9\\s,]+))\\)"
)