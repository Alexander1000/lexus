# concept of configure lexer analyzer language

regs:
    letter: [a-zA-Z]
    digit: [0-9]
    id: {letter}({letter}|{digit})*
    word: {letter}+
    path: ({letter}|{digit}|\.|\\)+

rules:

    main:
        t:plaintText:
            match: [^\{]+

        t:openControlTag:
            match: {%
            goto: open_control_tag

    open_control_tag:
        t:ws:
            match: \s+
            clean

        t:if:
            match: {word}
            equal: if

        t:for:
            match: {word}
            equal: for

        t:include:
            match: {word}
            equal: include
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
            match: {word}
            equal: with
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
