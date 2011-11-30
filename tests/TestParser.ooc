use proof
import proof

import parser/LemonParser

TEST_FILE := "../../tests/test.sbl"

test("parse file", func {
    parser:= LemonParser new()
    po:= parser parse(TEST_FILE)
})
