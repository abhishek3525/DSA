# Write your MySQL query statement below
select customer_id , count(*) as count_no_trans from Visits where Visit_id not in (select Distinct visit_id from Transactions) group by customer_id;