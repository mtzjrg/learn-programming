import requests
import sys

# Store api key in config.py outside of main file
from config import COINCAP_API_KEY

if len(sys.argv) != 2:
    sys.exit("Missing command-line argument")

try:
    purchase_amount = float(sys.argv[1])
except ValueError:
    sys.exit("Command-line argument is not a number")
else:
    api_key = COINCAP_API_KEY
    try:
        # response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
        response = requests.get(f"https://rest.coincap.io/v3/assets/bitcoin?apiKey={api_key}")
    except requests.RequestException:
        sys.exit()
    else:
        # bitcoin_price = response.json()["bpi"]["USD"]["rate_float"]
        bitcoin_price = response.json()["data"]["priceUsd"]
        amount_price = float(bitcoin_price) * purchase_amount

print(f"${amount_price:,.4f}")
