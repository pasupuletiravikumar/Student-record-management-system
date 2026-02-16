<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Record System</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: Arial, sans-serif;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            padding: 20px;
        }

        .container {
            max-width: 1400px;
            margin: 0 auto;
        }

        .header {
            background: white;
            padding: 30px;
            border-radius: 15px;
            margin-bottom: 20px;
            box-shadow: 0 5px 20px rgba(0,0,0,0.2);
        }

        .header h1 {
            color: #667eea;
            font-size: 32px;
        }

        .stats {
            display: grid;
            grid-template-columns: repeat(4, 1fr);
            gap: 15px;
            margin-bottom: 20px;
        }

        .stat-box {
            background: white;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 3px 10px rgba(0,0,0,0.1);
        }

        .stat-label {
            color: #666;
            font-size: 12px;
            margin-bottom: 5px;
        }

        .stat-value {
            color: #333;
            font-size: 28px;
            font-weight: bold;
        }

        .main-grid {
            display: grid;
            grid-template-columns: 350px 1fr;
            gap: 20px;
        }

        .card {
            background: white;
            padding: 25px;
            border-radius: 15px;
            box-shadow: 0 5px 20px rgba(0,0,0,0.2);
        }

        .card h2 {
            color: #333;
            margin-bottom: 20px;
            font-size: 20px;
        }

        .form-group {
            margin-bottom: 15px;
        }

        .form-group label {
            display: block;
            color: #555;
            font-weight: bold;
            margin-bottom: 5px;
        }

        .form-group input {
            width: 100%;
            padding: 10px;
            border: 2px solid #ddd;
            border-radius: 5px;
            font-size: 14px;
        }

        .form-group input:focus {
            outline: none;
            border-color: #667eea;
        }

        .btn {
            padding: 12px 20px;
            border: none;
            border-radius: 5px;
            font-size: 14px;
            font-weight: bold;
            cursor: pointer;
            width: 100%;
        }

        .btn-primary {
            background: #667eea;
            color: white;
        }

        .btn-primary:hover {
            background: #5568d3;
        }

        .btn-small {
            padding: 5px 10px;
            font-size: 12px;
            width: auto;
        }

        .btn-edit {
            background: #4CAF50;
            color: white;
        }

        .btn-delete {
            background: #f44336;
            color: white;
        }

        .search-box {
            margin-bottom: 15px;
        }

        .search-box input {
            width: 100%;
            padding: 10px;
            border: 2px solid #ddd;
            border-radius: 5px;
            font-size: 14px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
        }

        table th {
            background: #f5f5f5;
            padding: 12px;
            text-align: left;
            font-weight: bold;
            border-bottom: 2px solid #ddd;
        }

        table td {
            padding: 12px;
            border-bottom: 1px solid #eee;
        }

        table tr:hover {
            background: #f9f9f9;
        }

        .roll-badge {
            background: #667eea;
            color: white;
            padding: 4px 10px;
            border-radius: 4px;
            font-weight: bold;
        }

        .grade-A { background: #d4edda; color: #155724; padding: 4px 10px; border-radius: 4px; font-weight: bold; }
        .grade-B { background: #d1ecf1; color: #0c5460; padding: 4px 10px; border-radius: 4px; font-weight: bold; }
        .grade-C { background: #fff3cd; color: #856404; padding: 4px 10px; border-radius: 4px; font-weight: bold; }
        .grade-D { background: #f8d7da; color: #721c24; padding: 4px 10px; border-radius: 4px; font-weight: bold; }
        .grade-F { background: #f5c6cb; color: #721c24; padding: 4px 10px; border-radius: 4px; font-weight: bold; }

        .action-btns {
            display: flex;
            gap: 5px;
        }

        .message {
            padding: 12px;
            border-radius: 5px;
            margin-bottom: 15px;
            font-weight: bold;
        }

        .message-success {
            background: #d4edda;
            color: #155724;
        }

        .message-error {
            background: #f8d7da;
            color: #721c24;
        }

        .empty {
            text-align: center;
            padding: 30px;
            color: #999;
        }

        @media (max-width: 1024px) {
            .main-grid {
                grid-template-columns: 1fr;
            }
            .stats {
                grid-template-columns: repeat(2, 1fr);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>🎓 Student Record Management System</h1>
        </div>

        <div class="stats">
            <div class="stat-box">
                <div class="stat-label">TOTAL STUDENTS</div>
                <div class="stat-value" id="totalStudents">0</div>
            </div>
            <div class="stat-box">
                <div class="stat-label">AVERAGE MARKS</div>
                <div class="stat-value" id="averageMarks">0.0</div>
            </div>
            <div class="stat-box">
                <div class="stat-label">PASS RATE</div>
                <div class="stat-value" id="passRate">0%</div>
            </div>
            <div class="stat-box">
                <div class="stat-label">HIGHEST SCORE</div>
                <div class="stat-value" id="highestScore">0</div>
            </div>
        </div>

        <div id="messageContainer"></div>

        <div class="main-grid">
            <div class="card">
                <h2>Add New Student</h2>
                <div class="form-group">
                    <label>Roll Number</label>
                    <input type="number" id="rollNo" placeholder="Enter roll number">
                </div>
                <div class="form-group">
                    <label>Student Name</label>
                    <input type="text" id="studentName" placeholder="Enter student name">
                </div>
                <div class="form-group">
                    <label>Marks (0-100)</label>
                    <input type="number" id="marks" placeholder="Enter marks">
                </div>
                <button class="btn btn-primary" onclick="addStudent()">Add Student</button>
            </div>

            <div class="card">
                <h2>Student Records</h2>
                
                <div class="search-box">
                    <input type="text" id="searchInput" placeholder="Search by name or roll number..." onkeyup="searchStudents()">
                </div>

                <table>
                    <thead>
                        <tr>
                            <th>Roll No</th>
                            <th>Name</th>
                            <th>Marks</th>
                            <th>Grade</th>
                            <th>Actions</th>
                        </tr>
                    </thead>
                    <tbody id="tableBody">
                        <tr>
                            <td colspan="5" class="empty">No students added yet</td>
                        </tr>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

    <script>
        const MAX_STUDENTS = 100;
        let students = [];

        function showMessage(text, type) {
            const container = document.getElementById('messageContainer');
            container.innerHTML = '<div class="message message-' + type + '">' + text + '</div>';
            setTimeout(function() {
                container.innerHTML = '';
            }, 3000);
        }

        function getGrade(marks) {
            if (marks >= 90) return 'A';
            if (marks >= 75) return 'B';
            if (marks >= 60) return 'C';
            if (marks >= 40) return 'D';
            return 'F';
        }

        function addStudent() {
            const rollNo = document.getElementById('rollNo').value;
            const name = document.getElementById('studentName').value;
            const marks = document.getElementById('marks').value;

            // Validation
            if (!rollNo || !name || !marks) {
                showMessage('Please fill all fields!', 'error');
                return;
            }

            const rollNumber = parseInt(rollNo);
            const studentMarks = parseFloat(marks);

            if (rollNumber < 1) {
                showMessage('Roll number must be positive!', 'error');
                return;
            }

            if (studentMarks < 0 || studentMarks > 100) {
                showMessage('Marks must be between 0 and 100!', 'error');
                return;
            }

            if (students.length >= MAX_STUDENTS) {
                showMessage('Student limit reached (100 maximum)!', 'error');
                return;
            }

            // Check duplicate
            for (let i = 0; i < students.length; i++) {
                if (students[i].rollNo === rollNumber) {
                    showMessage('Roll number already exists!', 'error');
                    return;
                }
            }

            // Add student
            students.push({
                rollNo: rollNumber,
                name: name,
                marks: studentMarks
            });

            // Clear form
            document.getElementById('rollNo').value = '';
            document.getElementById('studentName').value = '';
            document.getElementById('marks').value = '';

            showMessage('Student added successfully!', 'success');
            updateDisplay();
        }

        function updateDisplay() {
            updateStats();
            displayTable();
        }

        function updateStats() {
            const total = students.length;
            document.getElementById('totalStudents').textContent = total;

            if (total === 0) {
                document.getElementById('averageMarks').textContent = '0.0';
                document.getElementById('passRate').textContent = '0%';
                document.getElementById('highestScore').textContent = '0';
                return;
            }

            let sum = 0;
            let passed = 0;
            let highest = 0;

            for (let i = 0; i < students.length; i++) {
                sum += students[i].marks;
                if (students[i].marks >= 40) {
                    passed++;
                }
                if (students[i].marks > highest) {
                    highest = students[i].marks;
                }
            }

            const average = sum / total;
            const passRate = (passed / total) * 100;

            document.getElementById('averageMarks').textContent = average.toFixed(1);
            document.getElementById('passRate').textContent = Math.round(passRate) + '%';
            document.getElementById('highestScore').textContent = highest.toFixed(1);
        }

        function displayTable() {
            const tbody = document.getElementById('tableBody');

            if (students.length === 0) {
                tbody.innerHTML = '<tr><td colspan="5" class="empty">No students added yet</td></tr>';
                return;
            }

            let html = '';
            for (let i = 0; i < students.length; i++) {
                const student = students[i];
                const grade = getGrade(student.marks);
                
                html += '<tr>';
                html += '<td><span class="roll-badge">#' + student.rollNo + '</span></td>';
                html += '<td><strong>' + student.name + '</strong></td>';
                html += '<td>' + student.marks.toFixed(1) + '</td>';
                html += '<td><span class="grade-' + grade + '">' + grade + '</span></td>';
                html += '<td><div class="action-btns">';
                html += '<button class="btn btn-small btn-delete" onclick="deleteStudent(' + i + ')">Delete</button>';
                html += '</div></td>';
                html += '</tr>';
            }

            tbody.innerHTML = html;
        }

        function deleteStudent(index) {
            const studentName = students[index].name;
            if (confirm('Delete ' + studentName + '?')) {
                students.splice(index, 1);
                showMessage('Student deleted successfully!', 'success');
                updateDisplay();
            }
        }

        function searchStudents() {
            const query = document.getElementById('searchInput').value.toLowerCase();
            const tbody = document.getElementById('tableBody');

            if (query === '') {
                displayTable();
                return;
            }

            let html = '';
            let found = 0;

            for (let i = 0; i < students.length; i++) {
                const student = students[i];
                const nameMatch = student.name.toLowerCase().indexOf(query) !== -1;
                const rollMatch = student.rollNo.toString().indexOf(query) !== -1;

                if (nameMatch || rollMatch) {
                    found++;
                    const grade = getGrade(student.marks);
                    
                    html += '<tr>';
                    html += '<td><span class="roll-badge">#' + student.rollNo + '</span></td>';
                    html += '<td><strong>' + student.name + '</strong></td>';
                    html += '<td>' + student.marks.toFixed(1) + '</td>';
                    html += '<td><span class="grade-' + grade + '">' + grade + '</span></td>';
                    html += '<td><div class="action-btns">';
                    html += '<button class="btn btn-small btn-delete" onclick="deleteStudent(' + i + ')">Delete</button>';
                    html += '</div></td>';
                    html += '</tr>';
                }
            }

            if (found === 0) {
                html = '<tr><td colspan="5" class="empty">No students found</td></tr>';
            }

            tbody.innerHTML = html;
        }
    </script>
</body>
</html>
