select machine_id,round((sum(p.proc)/count(*)),3) as processing_time from
(select a.machine_id, a.process_id ,(max(a.timestamp)-min(a.timestamp)) as proc
from activity as a inner join 
activity as aa where aa.machine_id=a.machine_id 
and aa.process_id=a.process_id
group by a.machine_id,a.process_id) as p group by machine_id;