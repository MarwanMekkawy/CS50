-- Keep a log of any SQL queries you execute as you solve the mystery.
--1-- getting crime description
 select description from crime_scene_reports
 where day = 28 and month = 7 and year = 2024 and street = 'Humphrey Street';

--2-- interviews transcripts
select name,transcript from interviews where day = 28 and month = 7 and year = 2024;

--3-- activities at bakery from 10:15 to 10:25am
select minute,activity, license_plate from bakery_security_logs
where day = 28 and month = 7 and year = 2024 and hour = 10 and minute >= 15 and minute <= 25;

--4-- suspect bank personal data
select people.name,people.phone_number,people.passport_number,people.license_plate
,atm_transactions.transaction_type,atm_transactions.amount
from people
join bank_accounts on bank_accounts.person_id = people.id
join atm_transactions on atm_transactions.account_number = bank_accounts.account_number
where atm_transactions.day = 28 and atm_transactions.month = 7
and atm_transactions.year = 2024 and atm_transactions.atm_location = 'Leggett Street';

--5-- joining the results from step 3 and 4 to narrow the list to[Bruce-Diana-Iman-Luca]
select people.name,people.phone_number,people.passport_number,people.license_plate
,atm_transactions.transaction_type,atm_transactions.amount
from people
join bank_accounts on bank_accounts.person_id = people.id
join atm_transactions on atm_transactions.account_number = bank_accounts.account_number
where atm_transactions.day = 28
and atm_transactions.month = 7
and atm_transactions.year = 2024
and atm_transactions.atm_location = 'Leggett Street'
and people.license_plate in (
    select license_plate from bakery_security_logs
    where day = 28 and month = 7 and year = 2024 and hour = 10 and minute >= 15 and minute <= 25
);

--6-- joining the results from 5 to flights data narrow the list to[Bruce-Luca]
select flights.hour,flights.destination_airport_id,airports.full_name,airports.city, people.name
from flights
join passengers on passengers.flight_id = flights.id
join people on people.passport_number = passengers.passport_number
join airports on airports.id = flights.destination_airport_id
where flights.day = 29
and flights.month = 7
and flights.year = 2024
and people.name in (
      select people.name
      from people
      join bank_accounts on bank_accounts.person_id = people.id
      join atm_transactions on atm_transactions.account_number = bank_accounts.account_number
      where atm_transactions.day = 28 and atm_transactions.month = 7
      and atm_transactions.year = 2024 and atm_transactions.atm_location = 'Leggett Street'
      and people.license_plate in (
            select license_plate
            from bakery_security_logs
            where day = 28 and month = 7 and year = 2024
            and hour = 10
            and minute between 15 and 25
        )
  )
order by flights.hour, flights.minute;

--7--  filtering suspects with caller and receiver [Bruce] to [Robin]
select people.name as caller_name,people2.name as receiver_name,phone_calls.duration
from phone_calls
join people on phone_calls.caller = people.phone_number
join people as people2 on phone_calls.receiver = people2.phone_number
where phone_calls.day = 28
and phone_calls.month = 7
and phone_calls.year = 2024
and phone_calls.duration < 60
and caller_name in ('Bruce','Luca');

