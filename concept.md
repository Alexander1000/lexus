# concept of configure lexer analyzer language

regs:
    letter: [a-zA-Z]
    digit: [0-9]
    id: {letter}({letter}|{digit})*
    path: ({letter}|{digit}|\.|\\)+

rules:

    state0:
        t:plaintText:
            match: [^\{]+

        t:openControlTag:
            match: {%
            goto: state1

    state1:
        t:if:
            match: if
        t:for:
            match: for

        t:include:
            match: include
            goto: state_include

        t:closeControlTag:
            match: %}
            return

        t:opMathLow:
            match: (+|-)

        t:opMathHigh:
            match: (*|/)

        t:boolOp:
            match: (and|or)

    state_include:
        t:fileName:
            match: "?{path}"?

        t:with:
            match: with
            goto: state_with

        t:closeControlTag:
            match: %}
            return

    state_with:
        t:openWithTag:
            match: {
            goto: state_with_key

        t:closeWithTag:
            match: }
            return

    state_with_key:
        t:withKey:
            match: {id}

        t:withComma:
            match: :
            goto: state_with_value

        default:
            return

    state_with_value:
        t:opMathLow:
            match: (+|-)

        t:opMathHigh:
            match: (*|/)

        t:boolOp:
            match: (and|or)

        t:withComma:
            match: ,
            return

        default:
            return
