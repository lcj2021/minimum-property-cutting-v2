select ?x ?y ?z where {
?x	<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>	 <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent> . 
?y	<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>	 <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#University> . 
?z	<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>	 <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Department> . 
?x	 <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>	?z . 
?x	 <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>	?y . 
?z	 <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>	?y . 
}