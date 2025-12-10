import json
import pycountry

try:
    with open("set_country_code.json") as f:
        data = json.load(f)

        country_name = data["country"]
        country_code = data["country-code"]

        if country_code == "default":
            country_obj = pycountry.countries.get(name=country_name)

            if country_obj:
                country_code = country_obj.alpha_2

                data["country-code"] = country_code
                
                with open("set_country_code.json", "w") as f:
                    json.dump(data, f, indent=2)

            else:
                raise ValueError(f"Country {country_name} not found in ISO database.")
            
except (FileNotFoundError, ValueError) as e:
    print(f"Error: {e}")