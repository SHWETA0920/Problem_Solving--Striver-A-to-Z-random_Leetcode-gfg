SELECT machine_id,
       ROUND(SUM(p.proc) / COUNT(*), 3) AS processing_time
FROM (
    SELECT a.machine_id,
           a.process_id,
           MAX(a.timestamp) - MIN(a.timestamp) AS proc
    FROM Activity AS a
    GROUP BY a.machine_id, a.process_id
) AS p
GROUP BY machine_id;