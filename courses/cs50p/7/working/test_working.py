import pytest
from working import convert


def test_valid():
    assert convert("12:30 PM to 12:43 AM") == "12:30 to 00:43"
    assert convert("5:39 PM to 11:19 AM") == "17:39 to 11:19"
    assert convert("10 PM to 8 AM") == "22:00 to 08:00"
    assert convert("12 AM to 12 PM") == "00:00 to 12:00"


def test_divider():
    with pytest.raises(ValueError):
        convert("3 AM - 3 PM")


def test_invalid():
    with pytest.raises(ValueError):
        convert("6:60 AM to 8:60 PM")
