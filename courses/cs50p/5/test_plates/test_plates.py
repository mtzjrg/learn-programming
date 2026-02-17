from plates import is_valid


def test_valid():
    assert is_valid("HI")
    assert is_valid("CS50")


def test_len():
    assert not is_valid("H")
    assert not is_valid("TOOLONG")


def test_start():
    assert not is_valid("F1")
    assert not is_valid("50CS")


def test_punc():
    assert not is_valid("PI3.14")


def test_digits():
    assert not is_valid("CS05")
    assert not is_valid("CS50P")
