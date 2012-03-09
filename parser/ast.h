/* Abstract Syntax Tree */

#ifndef _AST_H_
#define _AST_H_

#include <string.h>
#include "utils.h"


#define AST_ERROR()


//===========================================================================
// global typedefs
//===========================================================================
/*
 * Expression
 */
typedef struct HexExpr Expr;


/*
 * Statement
 */
typedef struct HexStmt Stmt;


/*
 * Suite
 */
typedef struct HexSuite Suite;
//===========================================================================
// global typedefs
//===========================================================================


/*
 * Literal
 */
typedef struct HexLiteral {
    enum {
        literal_type_char,          /* character literal */
        literal_type_string,        /* string literal */
        literal_type_integer,       /* integer literal */
        literal_type_float,         /* floating number literal */
    } literal_type;
    union {
        char literal_char;          /* character literal */
        char* literal_string;       /* string literal */
        int literal_integer;        /* integer literal */
        double literal_float;       /* floating number literal */
    };
} Literal;


//===========================================================================
// createLiteral() - construct an AST node of type Literal.
//===========================================================================
Literal* createLiteral(int type, void* value);


/*
 * Unary operator
 */
typedef enum HexUnaryOp {
    unary_op_plus,
    unary_op_minus,
    unary_op_inc,
    unary_op_dec,
    unary_op_bitwise_not,
    not
} UnaryOp;


/*
 * Assignment operator
 */
typedef enum HexAssignmentOp {
    assign_op,                  /* = */
    assign_op_new,              /* = new */
    assign_op_lazy_new,         /* = lazy new */
    assign_op_mul,              /* *= */
    assign_op_div,              /* /= */
    assign_op_mod,              /* %= */
    assign_op_plus,             /* += */
    assign_op_minus,            /* -= */
    assign_op_shift_left,       /* <<= */
    assign_op_shift_right,      /* >>= */
    assign_op_bitwise_not,      /* != */
    assign_op_bitwise_and,      /* &= */
    assign_op_bitwise_or,       /* |= */
    assign_op_bitwise_xor       /* ^= */
} AssignmentOp; 


/***********************************************************************
 *  Expression definitions
 ***********************************************************************/


/*
 * Primary expression
 */
typedef struct HexPrimaryExpr {
    enum {
        primary_expr_type_identifier,       /* identifier */
        primary_expr_type_literal,          /* literal */
        primary_expr_type_expr              /* expression */
    } primary_expr_type;
    union {
        char *primary_expr_identifier;      /* identifier */
        Literal* primary_expr_literal;      /* literal */
        Expr *primary_expr_expr;            /* expression */
    };
} PrimaryExpr;


//===========================================================================
// createPrimaryExpr() - construct an AST node of type PrimaryExpr.
//===========================================================================
Expr* createPrimaryExpr(int type, void* value);


/* 
 * Postfix expression
 *
 * Types:
 *  index: index expression
 *  inc_or_dec_post: post increment or post decrement   '++' or '--'
 *
 * Syntax:
 *  expr[index]
 *  expr()
 *  expr(arg_expr_list)
 *  expr.idenfitier
 *  expr++
 *  expr--
 */
typedef struct HexPostfixIndexExpr {Expr *index_expr; int index;} PostfixIndexExpr;
typedef struct PostfixAccessorExpr {Expr *expr; char *accessor;} PostfixAccessorExpr;
typedef struct HexPostfixExpr {
    enum {
        postfix_expr_type_index,                    /* index */
        postfix_expr_type_postfix_inc,              /* increment */
        postfix_expr_type_postfix_dec,              /* decrement */
        postfix_expr_type_accessor                  /* accessor */
    } postfix_expr_type;
    union {
        PostfixIndexExpr *postfix_expr_index_expr;            /* index */
        Expr *postfix_expr_postfix_inc_expr;                  /* increment */
        Expr *postfix_expr_postfix_dec_expr;                  /* decrement */            
        PostfixAccessorExpr *postfix_expr_accessor_expr;      /* accessor */
    };
} PostfixExpr;


//===========================================================================
// createPostfixExpr() - construct an AST node of type PostfixExpr.
//===========================================================================
Expr* createPostfixExpr(int type, void* value1, void* value2);


/*
 * Unary expression
 */
typedef struct HexPrefixUnaryOpExpr {Expr* expr; UnaryOp unary_op;} PrefixUnaryOpExpr;
typedef struct HexUnaryExpr {
    enum {
        unary_expr_type_prefix_inc,             /* prefix increment */
        unary_expr_type_prefix_dec,             /* prefix decrement */
        unary_expr_type_unary_op,               /* prefix unary operator */
        unary_expr_type_sizeof                  /* prefix sizeof */
    } unary_expr_type;
    union {
        Expr *unary_expr_prefix_inc_expr;                                   /* prefix increment */
        Expr *unary_expr_prefix_dec_expr;                                   /* prefix decrement */
        PrefixUnaryOpExpr *unary_expr_unary_op_expr;    /* prefix unary operator */
        Expr *unary_expr_sizeof_expr;                                       /* prefix sizeof */
    };
} UnaryExpr;


//===========================================================================
// createUnaryExpr() - construct an AST node of type UnaryExpr.
//===========================================================================
Expr* createUnaryExpr(int type, void* value1, void* value2);


/*
 * Cast expression 
 *
 * Syntax:
 *  target_expr = (cast_type)expr
 */
typedef struct HexCastExpr {
    Expr* cast_expr;
    char* cast_type;
} CastExpr;


//===========================================================================
// createCastExpr() - construct an AST node of type CastExpr.
//===========================================================================
Expr* createCastExpr(void* value1, void* value2);


/*
 * Multiplcative expression
 */
typedef struct HexMultiplicativeExpr {
    enum {
        multiplicative_expr_type_mul,
        multiplicative_expr_type_div,
        multiplicative_expr_type_mod
    } multi_expr_type;
    Expr* left_expr;
    Expr* right_expr;
} MultiplicativeExpr;


//===========================================================================
// createMultiplcativeExpr() - construct an AST node of type MultiplcativeExpr.
//===========================================================================
MultiplicativeExpr* createMultiplicativeExpr(int type, void* value1, void* value2);


/*
 * Additive expression
 */
typedef struct HexAdditiveExpr {
    enum {
        additive_expr_type_plus,
        additive_expr_type_minus
    } additive_expr_type;
    Expr* left_expr;
    Expr* right_expr;
} AdditiveExpr;


//===========================================================================
// createAdditiveExpr() - construct an AST node of type AdditiveExpr.
//===========================================================================
AdditiveExpr* createAdditiveExpr(int type, void* value1, void* value2);


/*
 * Arithmetic expression
 *
 * Types:
 *  multiplicative: multiplication and division '*' or '/'
 *  additive: addition and subtraction          '+' or '-'
 *
 * Syntax:
 *  target_expr = left_expr [ * | - | * | / ] right_expr
 */
typedef struct HexArithmeticExpr {
    enum {
        arithmetic_expr_type_multiplicative,
        arithmetic_expr_type_additive
    } arithmetic_expr_type;
    Expr* left_expr;
    Expr* right_expr;
} ArithmeticExpr;


//===========================================================================
// createArithmeticExpr() - construct an AST node of type ArithmeticExpr.
//===========================================================================
Expr* createArithmeticExpr(int type, void* value1, void* value2);


/*
 * Equality expression
 *
 * Types:
 *  eq: equal               '=='
 *  neq: not equal          "not"
 *  less: less than         '<'
 *  greater: greater than   '>'
 *  le: less or equal       "<="
 *  ge: greater or equal    ">="
 *
 * Syntax:
 *  target_expr = left_expr [ == | not | < | > | <= | >= ] right_expr
 */
typedef struct HexEqualityExpr {
    enum {
        equality_expr_type_eq,          /* == */
        equality_expr_type_neq,         /* != */
        equality_expr_type_less,        /* < */
        equality_expr_type_greater,     /* > */
        equality_expr_type_le,          /* <= */
        equality_expr_type_ge           /* >= */
    } equality_expr_type;
    Expr* left_expr;
    Expr* right_expr;
} EqualityExpr;


//===========================================================================
// createEqualityExpr() - construct an AST node of type EqualityExpr.
//===========================================================================
Expr* createEqualityExpr(int type, void* value1, void* value2);


/*
 * Logic expression 
 *  
 * Types:
 *  logic_and: logic and    "and"
 *  logic_or:  logic or     "or"
 *
 * Syntax:
 *  target_expr = left_expr [ and | or ] right_expr
 */
typedef struct HexLogicExpr {
    enum {
        logic_expr_type_logic_and,      /* and */
        logic_expr_type_logic_or        /* or */
    } logic_expr_type;
    Expr* left_expr;
    Expr* right_expr;
} LogicExpr;


//===========================================================================
// createLogicExpr() - construct an AST node of type LogicExpr.
//===========================================================================
Expr* createLogicExpr(int type, void* value1, void* value2);


/*
 * Bitwise expression 
 *  
 * Types:
 *  shift_left: left bitwise shift      "<<"
 *  shift_right: right bitwise shift    ">>"
 *  bitwise_and: bitwise AND            '&'
 *  bitwise_or: bitwise OR              '|'
 *  bitwise_xor: bitwise XOR            '^'
 *
 * Syntax:
 *  target_expr = left_expr [ >> | << | & | | | ^ ] right_expr
 */
typedef struct HexBitwiseExpr {
    enum {
        bitwise_expr_type_shift_left,       /* << */
        bitwise_expr_type_shift_right,      /* >> */
        bitwise_expr_type_bitwise_and,      /* & */
        bitwise_expr_type_bitwise_or,       /* | */
        bitwise_expr_type_bitwise_xor       /* ^ */
    } bitwise_expr_type;
    Expr* left_expr;
    Expr* right_expr;
} BitwiseExpr;


//===========================================================================
// createBitwiseExpr() - construct an AST node of type BitwiseExpr.
//===========================================================================
Expr* createBitwiseExpr(int type, void* value1, void* value2);


/*
 * Conditional expression 
 *  
 * Syntax:
 *  target_expr = consequent if predicate else alternative
 */
typedef struct HexConditionalExpr {
    Expr* consequent_expr;
    Expr* predicate_expr;
    Expr* alternative_expr;
} ConditionalExpr;


//===========================================================================
// createConditionalExpr() - construct an AST node of type ConditionalExpr.
//===========================================================================
Expr* createConditionalExpr(void* value1, void* value2, void* value3);


/*
 * Const expression
 */
typedef ConditionalExpr ConstExpr;


/*
 * Assignment expression 
 *  
 * Syntax:
 *  target_expr [ = | new | lazy new | *= | /= | += | -= | <<= | >>= | != | &= | |= | ^= ] expr
 */
typedef struct HexAssignmentExpr {
    AssignmentOp assignment_expr_op;
    Expr* left_expr;
    Expr* right_expr;
} AssignmentExpr;


//===========================================================================
// createAssignmentExpr() - construct an AST node of type AssignmentExpr.
//===========================================================================
Expr* createAssignmentExpr(int type, void* value1, void* value2);


/*
 * Argument expression
 *
 * Syntax:
 *  arg = assignmentExpr()
 *  arg = assignmentExpr() as alias
 */
typedef struct HexArgExpr {
    AssignmentExpr* assign_expr;    /* Assignment expression */
    char *alias;                    /* The identifier alias for that assignment expression. */
} ArgExpr;


/*
 * Argument expression list
 *
 *  A list of argument expressions.
 *
 * Syntax:
 *  (arg1, arg2 = assignmentExpr2(), arg3 = assignmentExpr3() as alias) 
 */
typedef struct HexArgExprList {                  
    ArgExpr *arg_expr;
    struct HexArgExprList *next;
} ArgExprList;


/*
 * Lambda expression 
 *  
 * Syntax:
 *  target_expr = (arg_init_list) => expr
 */
typedef struct HexLambdaExpr {
    struct ParameterList* lambda_param_list;
    Suite* lambda_suite;
} LambdaExpr;


//===========================================================================
// createLambdaExpr() - construct an AST node of type LambdaExpr.
//===========================================================================
Expr* createLambdaExpr(void* value1, void* value2);


/*
 * Expression.
 */
struct HexExpr {
    enum {
        expr_type_primary,
        expr_type_postfix,
        expr_type_unary,
        expr_type_cast,
        expr_type_arithmetic,
        expr_type_equality,
        expr_type_logic,
        expr_type_bitwise,
        expr_type_conditional,
        expr_type_assignment,
        expr_type_const,
        expr_type_lambda
    } expr_type;
    union {
        PrimaryExpr *primary_expr;
        PostfixExpr *postfix_expr;
        UnaryExpr *unary_expr;
        CastExpr *cast_expr;
        ArithmeticExpr *arithmetic_expr;
        EqualityExpr *equality_expr;
        LogicExpr *logic_expr;
        BitwiseExpr *bitwise_expr;
        ConditionalExpr *conditional_expr;
        AssignmentExpr *assignment_expr;
        ConstExpr *const_expr;
        LambdaExpr *lambda_expr;
    };
};


//===========================================================================
// createExpr() - construct an AST node of type Expr.
//===========================================================================
Expr* createExpr(int type, void* value);


/*
 * Expression list
 */
typedef struct HexExprList {
    Expr *expr;
    struct HexExprList *next;
} ExprList;


//===========================================================================
// createExprList() - construct an AST node of type ExprList.
//===========================================================================
ExprList *createExprList(Expr* expr, ExprList* parent_list);


/***********************************************************************
 *  Declaration definitions
 ***********************************************************************/

/*
 * Storage class specifier
 */
typedef enum HexStorageClassSpecifier {
    storage_class_specifier_static          /* static */
} StorageClassSpecifier;


/*
 * Type specifier
 */
typedef enum HexTypeSpecifier {
    type_specifier_char,            /* type char */
    type_specifier_short,           /* type short */
    type_specifier_int,             /* type int */
    type_specifier_long,            /* type long */
    type_specifier_float,           /* type float */
    type_specifier_double,          /* type double */
    type_specifier_uchar,           /* type uchar */
    type_specifier_ushort,          /* type ushort */
    type_specifier_uint,            /* type uint */
    type_specifier_ulong,           /* type ulong */
    type_specifier_identifier       /* custom type */
} TypeSpecifier;


/*
 * Type qualifier
 */
typedef enum HexTypeQualifier {
    type_qualifier_const,           /* qualifier const */
    type_qualifier_volatile         /* qualifier volatile */
} TypeQualifier;


/*
 * Type qualifier list
 */
typedef struct HexTypeQualifierList {
    TypeQualifier type_qualifier;
    struct HexTypeQualifierList *next;
} TypeQualifierList;


//===========================================================================
// createTypeQualifierList() - construct an AST node of type TypeQualifierList.
//===========================================================================
TypeQualifierList* createTypeQualifierList(TypeQualifier qualifier, TypeQualifierList* parent_list);


/*
 * Direct declarator
 */
typedef struct HexDirectDeclarator {
    enum {
        declarator_identifier_type,      /* corresponds to IDENTIFIER */
        declarator_const_index_type,     /* corresponds to direct_declarator '[' const_expr ']' */
        declarator_empty_index_type      /* corresponds to direct_declarator '[' ']' */
    } type;
    union {
        char *identifier;
        struct { struct HexDirectDeclarator* declarator; ConstExpr* const_expr;} const_index_declarator;
        struct { struct HexDirectDeclarator* declarator;} empty_index_declarator;
    };
} DirectDeclarator;


/*
 * Declarator
 */
typedef DirectDeclarator Declarator;


/*
 * Init declarator list
 */
typedef struct HexInitDeclaratorList {
    Declarator *declarator;
    struct HexInitDeclaratorList* next;
} InitDeclaratorList;


/*
 * Declaration specifier
 */
typedef struct HexDeclarationSpecifiers {
    StorageClassSpecifier storage_class_specifier;
    TypeSpecifier type_specifier;
    struct HexDeclarationSpecifiers *declaration_specifiers;
} DeclarationSpecifiers;


/*
 *  Declaration
 */
typedef struct HexDeclaration {
    DeclarationSpecifiers *declaration_specifiers;
    InitDeclaratorList *init_declarator_list;
} Declaration;


/*
 * Identifier list
 */
typedef struct HexIdentifierList {
    Literal* identifier_literal;
    struct HexIdentifierList *next;
} IdentifierList;


//===========================================================================
// createIdentifierList() - construct an AST node of type IdentifierList.
//===========================================================================
IdentifierList* createIdentifierList(Literal* literal, IdentifierList* parent_list);


/***********************************************************************
 *  Parameter definitions
 ***********************************************************************/

/*
 * Parameter declaration
 */
typedef struct HexParameterDeclaration {
    enum {
        param_declaration_type_simple,  /* single identifier parameter */
        param_declaration_type_complex  /* other types of param with optional declaration specifiers. */
    } type;
    union {
        char *identifier;
        struct {
            DeclarationSpecifiers *declaration_specifier;
            Declarator *declarator;
        };
    };
} ParameterDeclaration;


/*
 * Parameter list
 */
typedef struct HexParameterList {
    ParameterDeclaration *param_declaration;
    struct HexParameterList *next;
} ParameterList;


/*
 * Parameter type list
 */
typedef struct HexParameterTypeList {
    ParameterList *param_list;
    int is_varadic;             /* whether parameter list has elipsis at the end. */
} ParameterTypeList;


/***********************************************************************
 *  Initializer definitions
 ***********************************************************************/

/*
 * Data struct typedefs
 */
typedef struct HexListInitializerList ListInitializerList;
typedef struct HexArrayInitializerList ArrayInitializerList;
typedef struct HexTupleInitializerList TupleInitializerList;
typedef struct HexStructInitializerList StructInitializerList;
typedef struct HexSetInitializerList SetInitializerList;
typedef struct HexMapInitializerList MapInitializerList;
typedef struct HexMultimapInitializerList MultimapInitializerList;


/*
 * Initializer
 */
typedef struct HexInitializer {
    enum {
        initializer_type_assign_expr,                           /* assignment expression initializer */
        initializer_type_list,                                  /* list initializer */
        initializer_type_array,                                 /* array initializer */
        initializer_type_tuple,                                 /* tuple initializer */
        initializer_type_struct,                                /* struct initializer */
        initializer_type_set,                                   /* set initializer */
        initializer_type_map,                                   /* map initializer */
        initializer_type_multimap                               /* multimap initializer */
    } initializer_type;
    union {
        AssignmentExpr *assignment_expr;                        /* assignment expression initializer */
        ListInitializerList *list_initializer_list;             /* list initializer */
        ArrayInitializerList *array_initializer_list;           /* array initializer */
        TupleInitializerList *tuple_initializer_list;           /* tuple initializer */
        StructInitializerList *struct_initializer_list;         /* struct initializer */
        SetInitializerList *set_initialier_list;                /* set initializer */
        MapInitializerList *map_initializer_list;               /* map initializer */
        MultimapInitializerList *multimap_initializer_list;     /* multimap initializer */
    };
} Initializer;


//===========================================================================
// createInitializer() - construct an AST node of type Initializer.
//===========================================================================
Initializer* createInitializer(int type, void* value);


/*
 *  List initializer list 
 */
struct HexListInitializerList {
    Initializer *initializer;
    struct HexListInitializerList *next;
};


//===========================================================================
// createListInitializerList() - construct an AST node of type ListInitializerList.
//===========================================================================
ListInitializerList* createListInitializerList(Initializer* initializer, ListInitializerList* parent_list);


/*
 * Array initializer list
 */
struct ArrayInitializerList {
    Initializer *initializer;
    ArrayInitializerList *array_initializer_list;
};


/*
 * Tuple initializer list
 */
struct TupleInitializerList {
    Initializer *initializer;
    TupleInitializerList *tuple_initializer_list;
};


/*
 * Struct initializer list
 */
struct StructInitializerList {
    enum {
        struct_value_type_literal,      /* if prop value is literal */
        struct_value_type_initializer   /* if prop value is initializer */
    } value_type;
    union {
        Literal *struct_value_literal;
        Initializer *initializer;
    };
    StructInitializerList *struct_initializer_list;
};


/*
 * Set initializer list
 */
struct SetInitializerList {
    Initializer *initializer;
    SetInitializerList *set_initializer_list;
};


/*
 * Map initializer list
 */
struct MapInitializerList {
    Literal *key;
    Initializer *value;
    MapInitializerList *map_initializer_list;
};


/*
 * Multimap initializer list
 */
struct MultimapInitializerList {
    Literal *key;
    MapInitializerList *values;
    MultimapInitializerList *multimap_initializer_list;
};


/***********************************************************************
 *  Statement definitions
 ***********************************************************************/


/*
 * Simple statement
 */
typedef struct HexSimpleStmt SimpleStmt;


/*
 * Statement list
 */
typedef struct HexStmtList {
    SimpleStmt *simple_stmt;
    struct HexStmtList *next;
} StmtList;


/*
 * Module
 */
typedef struct HexModule {
    char *identifier;
    struct HexModule *next;
} Module;


/*
 * Relative module
 */
typedef struct HexRelativeModule {
    Module *module;
} RelativeModule;


/*
 * Import statement
 */
typedef struct HexImportStmt {
    RelativeModule *relative_module;
    char *alias;
} ImportStmt;


/*
 * Expression statement
 */
typedef struct HexExprStmt {
    ExprList *expr_list;
} ExprStmt;


/*
 * Elif statement
 */
typedef struct HexElifStmt {
    Expr *elif_expr;
    Suite *elif_suite;
    struct HexElifStmt *next_elif_stmt;
} ElifStmt;


/*
 * Else statement
 */
typedef struct HexElseStmt {
    Suite *else_suite;
} ElseStmt;


/*
 * If statement
 */
typedef struct HexIfStmt {
    Expr *if_expr;
    Suite *if_suite;
    ElifStmt *elif_stmt;
    ElseStmt *else_stmt;
} IfStmt;


/*
 * While statement
 */
typedef struct HexWhileStmt {
    Expr *while_expr;
    Suite *while_suite;
} WhileStmt;


/*
 * Do-while statement
 */
typedef struct HexDoWhileStmt {
    Suite *dowhile_suite;
    Expr *dowhile_expr;
} DoWhileStmt;


/*
 * Catch statement
 */
typedef struct HexCatchStmt {
    Expr *catch_expr;
    Suite *catch_suite;
} CatchStmt;


/*
 * Catch statement group
 */
typedef struct HexCatchStmtGroup {
    CatchStmt* catch_stmt;
    struct HexCatchStmtGroup *next;
} CatchStmtGroup;


/*
 * Finally statement
 */
typedef struct HexFinallyStmt {
    Suite* finally_suite;
} FinallyStmt;


/*
 * Try statement
 */
typedef struct HexTryStmt {
    Suite *try_suite;
    CatchStmtGroup *catch_stmt_group;
    FinallyStmt *finally_stmt;
} TryStmt;


/*
 * Return statement
 */
typedef struct HexReturnStmt {
    ExprList *return_expr_list;
} ReturnStmt;


/*
 * Continue statement
 */
typedef struct HexContinueStmt ContinueStmt;


/*
 * Break statement
 */
typedef struct HexBreakStmt BreakStmt;


/*
 * Pass statement
 */
typedef struct HexPassStmt PassStmt;


/*
 * Function definition
 */
typedef struct HexFuncDef FuncDef;


/*
 * Compound statement
 */
typedef struct HexCompoundStmt {
    enum {
        compound_stmt_type_if_stmt,             /* if statement */
        compound_stmt_type_while_stmt,          /* while statement */
        compound_stmt_type_try_stmt,            /* try statement */
        compound_stmt_type_func_def             /* function definition */
    } compound_stmt_type;
    union {
        IfStmt *compound_stmt_if_stmt;          /* if statement */
        WhileStmt *compound_stmt_while_stmt;    /* while statement */
        TryStmt *compound_stmt_try_stmt;        /* try statement */
        FuncDef *compound_stmt_func_def;        /* function definition */
    };
} CompoundStmt;


//===========================================================================
// createCompoundStmt() - construct an AST node of type CompoundStmt.
//===========================================================================
CompoundStmt* createCompoundStmt(int type, void* value);



/***********************************************************************
 *  Function definitions
 ***********************************************************************/


/*
 * Function declaration specifier
 */
typedef struct HexDeclarationSpecifiers FuncDeclarationSpecifiers;


/*
 * Function definition
 */
struct FuncDef {
    FuncDeclarationSpecifiers *func_declaration_specifiers;
    char *func_name;
    ParameterTypeList *func_parameters;
    Suite *func_suite;
};


#endif // _AST_H_