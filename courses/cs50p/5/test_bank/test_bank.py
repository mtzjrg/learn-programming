from bank import value


def test_zero():
    assert value("Hello, sir.") == 0


def test_twenty():
    assert value("hey, what's up?") == 20


def test_hundred():
    assert value("  Do I know you? ") == 100
