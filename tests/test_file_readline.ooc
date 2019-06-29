use proof
import proof

import io/StringReader
import io/FileReader

test("StringReader parses 2 non-empty lines", func {
    reader := StringReader new~withString("1\n2\n")
    lastline := (null as String)
    line1 := reader readLine()
    assert(line1 == "1")
    line2 := reader readLine()
    assert(line2 == "2")
    assert(!(reader hasNext?()))
})

test("FileReader parses 2 non-empty lines, and a weird 3rd line", func {
    reader := FileReader new~withName("../onetwo.txt")
    lastline := (null as String)
    line1 := reader readLine()
    assert(line1 == "1")
    line2 := reader readLine()
    assert(line2 == "2")

    assert(reader hasNext?()) // ??
    line3 := reader readLine()

    assert(!(reader hasNext?()))

    printf("\nLast line size: %i Last line first char: %i\n", line3 length(), line3[0])

    // trim the single null char
    assert((line3 trim(0 as Char)) empty?())

    assert~withMessage(line3 empty?(), "last line is not empty")
})

