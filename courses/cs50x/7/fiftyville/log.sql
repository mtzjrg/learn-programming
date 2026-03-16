-- Keep a log of any SQL queries you execute as you solve the mystery.

/* CRIME SCENE REPORT
 ************************************************************************
 * Check crime scene reports for any mentions of CS50 duck theft. Robbery
 * occured at Humphrey Street Bakery at 10:15am, three witnesses were
 * interviewed.
 */

SELECT description FROM crime_scene_reports
 WHERE description LIKE '%CS50%';

/* INTERVIEWS
 ****************************************************************************
 *    Ruth: Thief seen leaving in a car from the bakery parking lot within 10
 *          minutes of the theft.
 *  Eugene: Thief was seen at ATM on Leggett Street earlier during the day
 *          withdrawing money.
 * Raymond: Thief was seen making a phone call after leaving the bakery,
 *          mentioned leaving Fiftyville on the earliest flight the next day,
 *          asked accomplice to purchase flight ticket over the phone.
 */

SELECT name, transcript
  FROM interviews
 WHERE transcript LIKE '%thief%bakery%';

/* LEADS
 *****************************************************************************
 * Suspected thief:
 *  Check bakery security logs for car plates within time of crime.
 *  Check ATM transactions from 2023-07-28 before 10:15am.
 *  Check suspect bank accounts for more information.
 *  Check phone calls from 2023-07-28 after 10:15am that are under one minute.
 *  Check earliest flight for 2023-07-28 for matching person id and passport
 *  number.
 *
 * Suspected destination:
 *  Check id from suspect's flight for destination airport
 *
 * Suspected accomplice:
 *  Check phone calls for reciever whose caller matches suspect's phone_number
 */

WITH sus_phone_calls AS (
    SELECT caller, receiver
      FROM phone_calls
     WHERE duration < 60
       AND day = 28
), sus_flight AS (
    SELECT id, destination_airport_id
      FROM flights
     WHERE origin_airport_id IN (
        SELECT id
          FROM airports
         WHERE city = 'Fiftyville'
     ) AND day = 29
     ORDER BY hour
     LIMIT 1
), sus_passengers AS (
    SELECT passport_number
      FROM passengers
     WHERE flight_id IN (
        SELECT id
          FROM sus_flight
     )
), sus_plates AS (
    SELECT license_plate
      FROM bakery_security_logs
     WHERE activity = 'exit'
       AND day = 28
       AND hour = 10
       AND minute BETWEEN 15 AND 25
), sus_person_ids AS (
    SELECT person_id
      FROM atm_transactions
      JOIN bank_accounts on atm_transactions.account_number = bank_accounts.account_number
       AND atm_transactions.day = 28
       AND atm_transactions.atm_location = 'Leggett Street'
       AND atm_transactions.transaction_type = 'withdraw'
), primary_suspect AS (
    SELECT * FROM people
     WHERE phone_number IN (SELECT caller FROM sus_phone_calls)
       AND passport_number IN (SELECT passport_number FROM sus_passengers)
       AND license_plate IN (SELECT license_plate FROM sus_plates)
       AND id IN (SELECT person_id FROM sus_person_ids)
), accomplice AS (
    SELECT * FROM people
     WHERE phone_number in (
        SELECT receiver
          FROM sus_phone_calls
         WHERE caller = (SELECT phone_number FROM primary_suspect)
    )
), destination AS (
    SELECT city FROM airports
     WHERE id = (SELECT destination_airport_id FROM sus_flight)
)
SELECT p.*, d.city AS destination
FROM primary_suspect p
CROSS JOIN destination d
UNION ALL
SELECT a.*, NULL AS destination
FROM accomplice a;

/* RESULTS
 ****************************
 * Thief: Bruce
 * Destination: New York City
 * Accomplice: Robin
 */
