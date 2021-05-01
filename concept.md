# concept of configure lexer analyzer language

regs:
    letter: [a-zA-Z]
    digit: [0-9]
    id: {letter}({letter}|{digit})*

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

        t:closeControlTag:
            match: %}
            goto: state0

        t:opMathLow:
            match: (+|-)

        t:opMathHigh:
            match: (*|/)

        t:boolOp:
            match: (and|or)
