import json
from datetime import date
from datetime import datetime

def dateValidation():
    try:
        with open("user_bday.json") as f:
            data = json.load(f)

        day = data["day"]
        month = data["month"]
        year = data["year"]

        try:
            datetime.strptime(f"{day:02d}.{month:02d}.{year}", "%d.%m.%Y")

            data["date-value"] = True
            data["final-bday"] = [day, month, year]

            today = date.today()
            birthday = date(year, month, day)

            age_verification = today.year - birthday.year - ((today.month, today.day) < (birthday.month, birthday.day))

            if age_verification >= 18:
                data["age-type"] = True

            elif age_verification < 18:
                data["age-type"] = False

        except ValueError as e:
            data["date-value"] = False
            data["final-bday"] = []
            print(e)

        with open("user_bday.json", "w") as f:
            json.dump(data, f, indent=4)
    
    except (FileNotFoundError, KeyError) as e:
        print(e)